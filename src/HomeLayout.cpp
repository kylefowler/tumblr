/*
 * HomeLayout.cpp
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#include "HomeLayout.h"

#include <bb/cascades/controls/listview.h>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/Button>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DockLayoutProperties>
#include <bb/cascades/animation/fadetransition.h>
#include <bb/cascades/animation/groupanimation.h>
#include "PostItemFactory.h"
#include "PostCreateLayout.h"

HomeLayout::HomeLayout(User *homeUser) :
                CustomControl() ,
				dashboardModel()
{
	QmlDocument *qml = QmlDocument::create("tumblrhome.qml");
	qml->setContextProperty("lg", this);

	user = homeUser;
	Control *root = qml->createRootNode<Control>();
	blogTitle = root->findChild<Label*>("loginName");
	blogUrl = root->findChild<Label*>("url");
	blogList = root->findChild<ListView*>("blogList");
	actionStatus = root->findChild<Label*>("actionStatus");

	blogTitle->setText(user->getName());
	blogUrl->setText(user->getBlogs().at(0)->getUrl());

    logoutButton = root->findChild<Button*>("logoutButton");
    connect(logoutButton, SIGNAL(clicked()), this, SLOT(onLogoutClicked()));
    refreshButton = root->findChild<Button*>("refreshButton");
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(onRefreshClicked()));
    postButton = root->findChild<Button*>("postButton");
    connect(postButton, SIGNAL(clicked()), this, SLOT(onPostClicked()));
    reblogButton = root->findChild<Button*>("reblogButton");
    connect(reblogButton, SIGNAL(clicked()), this, SLOT(onReblogClicked()));
    likeButton = root->findChild<Button*>("likeButton");
    connect(likeButton, SIGNAL(clicked()), this, SLOT(onLikeClicked()));

	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::DashboardObj, TumblrApi::instance()->getUserDashboard(20,0,NULL,0,false,false));
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onDashboardDataLoad(AbstractObjectBase*)));
	env->makeRequest();

	bb::cascades::CustomControl::setRoot(root);
}

HomeLayout::~HomeLayout() {
	delete blogList;
	delete blogTitle;
	delete blogUrl;
}

void HomeLayout::onDashboardDataLoad(AbstractObjectBase* user) {
	DashboardResponse* usr = dynamic_cast<DashboardResponse*>(user);
	dashboard = usr;
	QList<Post*> posts = dashboard->getPosts();
	QVariantList list;
	dashboardModel.clear();
	foreach(Post* p, posts) {
		QVariant var;
		var.setValue(p);
		dashboardModel << var;
	}
	blogList->setDataModel(&dashboardModel);
	PostItemFactory* factory = new PostItemFactory();
	blogList->setListItemManager(factory);
}

void HomeLayout::onRefreshClicked() {
	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::DashboardObj, TumblrApi::instance()->getUserDashboard(20,0,NULL,0,false,false));
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onDashboardDataLoad(AbstractObjectBase*)));
	env->makeRequest();
}

void HomeLayout::onLogoutClicked() {
	TumblrApi::instance()->logout();
	Tumblr::instance()->nav->pop();
}

void HomeLayout::onPostClicked() {
	PostCreateLayout *create = new PostCreateLayout(user->getBlogs().at(0));
	Tumblr::instance()->nav->push(create);
}

void HomeLayout::onReblogClicked()
{
	QVariantList p = blogList->selected();
	Post* post = dashboardModel.value(p.at(0).toInt()).value<Post*>();
	QUrl url = QUrl(user->getBlogs().at(0)->getUrl());
	KQOAuthRequest* req = TumblrApi::instance()->reblogPost(url.host(),post->getType(),post->getId(),post->getReblogKey());
	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::Empty, req);
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onReblogSuccess(AbstractObjectBase*)));
	env->makeRequest();
}

void HomeLayout::onLikeClicked() {
	QVariantList p = blogList->selected();
	Post* post = dashboardModel.value(p.at(0).toInt()).value<Post*>();
	KQOAuthRequest* req = TumblrApi::instance()->likePost(post->getId(),post->getReblogKey());
	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::Empty, req);
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onLikeSuccess(AbstractObjectBase*)));
	env->makeRequest();
}

void HomeLayout::onReblogSuccess(AbstractObjectBase* resp) {
	Q_UNUSED(resp);
	actionStatus->setText("Reblogged!");
	SequentialAnimation* anim = SequentialAnimation::create(actionStatus)
							.add(FadeTransition::create(actionStatus).from(0.0f).to(1.0f).duration(1000))
							.add(FadeTransition::create(actionStatus).from(1.0f).to(0.0f).duration(1000)).autoDeleted(true);
	anim->play();
}

void HomeLayout::onLikeSuccess(AbstractObjectBase* resp) {
	Q_UNUSED(resp);
	actionStatus->setText("Liked!");
	SequentialAnimation* anim = SequentialAnimation::create(actionStatus)
							.add(FadeTransition::create(actionStatus).from(0.0f).to(1.0f).duration(1000))
							.add(FadeTransition::create(actionStatus).from(1.0f).to(0.0f).duration(1000)).autoDeleted(true);
	anim->play();
}
