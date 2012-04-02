/*
 * HomeLayout.cpp
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#include "PostCreateLayout.h"

#include <bb/cascades/controls/listview.h>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/Button>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DockLayoutProperties>
#include "PostTypeItemFactory.h"

PostCreateLayout::PostCreateLayout(Blog *postingBlog) :
                CustomControl() ,
				postTypeModel()
{
	QmlDocument *qml = QmlDocument::create("tumblrpost.qml");
	qml->setContextProperty("tp", this);

	blog = postingBlog;
	Control *root = qml->createRootNode<Control>();
	postTitle = root->findChild<TextField*>("postTitle");
	postContent = root->findChild<TextArea*>("postTextContent");
	postTypeList = root->findChild<ListView*>("postTypeList");

    postButton = root->findChild<Button*>("postButton");
    connect(postButton, SIGNAL(clicked()), this, SLOT(onPostClicked()));

    postTypeModel << QVariant("Text");
    postTypeModel << QVariant("Photo");
    postTypeModel << QVariant("Quote");
    postTypeModel << QVariant("Link");
    postTypeModel << QVariant("Chat");
    postTypeModel << QVariant("Audio");
    postTypeModel << QVariant("Video");

    postTypeList->setDataModel(&postTypeModel);
    PostTypeItemFactory* factory = new PostTypeItemFactory();
    postTypeList->setListItemManager(factory);

	bb::cascades::CustomControl::setRoot(root);
}

PostCreateLayout::~PostCreateLayout() {
	delete postTitle;
	delete postContent;
	delete postTypeList;
	delete postButton;
}

void PostCreateLayout::onPostClicked() {
	QUrl url = QUrl(blog->getUrl());
	qDebug() << url.host() + "________________";
	KQOAuthRequest* req = TumblrApi::instance()->makeTextPost(url.host(),postContent->text(),postTitle->text());
	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::PostObj, req);
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onPostComplete(AbstractObjectBase*)));
	env->makeRequest();
}

void PostCreateLayout::onPostComplete(AbstractObjectBase* post) {
	Q_UNUSED(post);
	qDebug() << "Post Created!";
}

