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
#include "PostItemFactory.h"

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

	blogTitle->setText(user->getName());
	blogUrl->setText(user->getBlogs().at(0)->getUrl());

    logoutButton = root->findChild<Button*>("loginButton");
    connect(logoutButton, SIGNAL(clicked()), this, SLOT(onLogoutClicked()));
    refreshButton = root->findChild<Button*>("refreshButton");
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(onRefreshClicked()));

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
	Tumblr::instance()->nav->pop();
}


