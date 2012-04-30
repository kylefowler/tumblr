/*
 * TumblrApi.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#include "TumblrApi.h"

TumblrApi* TumblrApi::m_instance = NULL;

const QString TumblrApi::CONSUMER_KEY = QString("Ok4M3RrFHqfJ6GcuZUDf7CIeoudqLpME9QnVWU0YBkQgUqsMSE");
const QString TumblrApi::CONSUMER_SECRET = QString("wREgyKwiZYlKXrJqnLpNpXF28JoSN1fDYST0fgB5sm9DctE5Re");
const QString TumblrApi::API_BASE = QString("http://api.tumblr.com/v2/");

TumblrApi::TumblrApi() {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager(this);
    //this file should be a file path relative to the assets directory
    oauthManager->setSuccessHtmlFile("success.html");
    oauthRequest->setEnableDebugOutput(true);
}

TumblrApi::~TumblrApi() {
    delete oauthRequest;
    delete oauthManager;
}

TumblrApi* TumblrApi::instance() {
	if(!m_instance) {
		m_instance = new TumblrApi;
	}
	return m_instance;
}

KQOAuthManager* TumblrApi::getRequestManager() {
	return oauthManager;
}

void TumblrApi::onTemporaryTokenReceived(QString token, QString tokenSecret)
{
    qDebug() << "Temporary token received: " << token << tokenSecret;

    QUrl userAuthURL("http://www.tumblr.com/oauth/authorize");

    if( oauthManager->lastError() == KQOAuthManager::NoError) {
        qDebug() << "Asking for user's permission to access protected resources. Opening URL: " << userAuthURL;
        oauthManager->getUserAuthorization(userAuthURL);
    }

}

void TumblrApi::onAuthorizationReceived(QString token, QString verifier) {
    qDebug() << "User authorization received: " << token << verifier;

    oauthManager->getUserAccessTokens(QUrl("http://www.tumblr.com/oauth/access_token"));
    if( oauthManager->lastError() != KQOAuthManager::NoError) {
        emit loginComplete(false);
    }
}

void TumblrApi::onAccessTokenReceived(QString token, QString tokenSecret) {
    qDebug() << "Access token received: " << token << tokenSecret;

    disconnect(oauthManager, SIGNAL(accessTokenReceived(QString,QString)), this, SLOT(onAccessTokenReceived(QString,QString)));

    if(token == NULL) {
    	emit loginComplete(false);
    	return;
    }
    oauthSettings.setValue("oauth_token", token);
    oauthSettings.setValue("oauth_token_secret", tokenSecret);

    emit loginComplete(token.length() > 0);
    qDebug() << "Access tokens now stored.";
}

void TumblrApi::onAuthorizedRequestDone() {
    qDebug() << "Request sent to Twitter!";
}

void TumblrApi::onRequestReady(QByteArray response) {
    qDebug() << "Response from the service: " << response;
    disconnect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestReady(QByteArray)));
}

void TumblrApi::xauth(QString username, QString password) {
    connect(oauthManager, SIGNAL(accessTokenReceived(QString,QString)), this, SLOT(onAccessTokenReceived(QString,QString)));
    connect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestReady(QByteArray)));

    //oauthManager->getOauth2UserAuthorization(QUrl("https://foursquare.com/oauth2/authenticate"),"GQEGG11DQ15FNPHH3CI0QU5PXGEMLMZTD3121KBTWQIENTDJ");
    KQOAuthRequest_XAuth *oauthRequest = new KQOAuthRequest_XAuth(this);
    oauthRequest->initRequest(KQOAuthRequest::AccessToken, QUrl("http://www.tumblr.com/oauth/access_token"));
    oauthRequest->setConsumerKey(CONSUMER_KEY);
    oauthRequest->setConsumerSecretKey(CONSUMER_SECRET);
    oauthRequest->setXAuthLogin(username,password);

    oauthManager->executeRequest(oauthRequest);
}

void TumblrApi::getAccess()
{
    connect(oauthManager, SIGNAL(temporaryTokenReceived(QString,QString)), this, SLOT(onTemporaryTokenReceived(QString, QString)));
    connect(oauthManager, SIGNAL(authorizationReceived(QString,QString)), this, SLOT( onAuthorizationReceived(QString, QString)));
    connect(oauthManager, SIGNAL(accessTokenReceived(QString,QString)), this, SLOT(onAccessTokenReceived(QString,QString)));
    connect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestReady(QByteArray)));

    oauthRequest->initRequest(KQOAuthRequest::TemporaryCredentials, QUrl("http://www.tumblr.com/oauth/request_token"));
    oauthRequest->setConsumerKey("Ok4M3RrFHqfJ6GcuZUDf7CIeoudqLpME9QnVWU0YBkQgUqsMSE");
    oauthRequest->setConsumerSecretKey("wREgyKwiZYlKXrJqnLpNpXF28JoSN1fDYST0fgB5sm9DctE5Re");
    oauthManager->setHandleUserAuthorization(true);
    oauthManager->executeRequest(oauthRequest);
}

bool TumblrApi::checkToken() {
	return oauthSettings.value("oauth_token_secret").toString().isEmpty() || oauthSettings.value("oauth_token").toString().isEmpty();
}

KQOAuthRequest* TumblrApi::getUserInfo() {
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	if(!checkToken()) {
		xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "user/info"));
		addAuth(xRequest);
		xRequest->setHttpMethod(KQOAuthRequest::POST);
	}
	return xRequest;
}

KQOAuthRequest* TumblrApi::getUserDashboard(int limit,int offset, QString type,long sinceId,bool reblogInfo, bool notesInfo) {
	Q_UNUSED(reblogInfo);
	Q_UNUSED(notesInfo);
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	if(!checkToken()) {
		xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "user/dashboard"));
		addAuth(xRequest);
		xRequest->setHttpMethod(KQOAuthRequest::GET);
	}
	KQOAuthParameters params;
	params.insert("limit", QString::number(limit));
	params.insert("offset", QString::number(offset));
	if(type != NULL && type.length() > 0) {
		params.insert("type", type);
	}
	if(sinceId > 0) {
		params.insert("since_id", QString::number(sinceId));
	}
	xRequest->setAdditionalParameters(params);
	return xRequest;
}

KQOAuthRequest* TumblrApi::makeTextPost(QString blogName, QString body, QString title){
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	if(!checkToken()) {
		xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "blog/" + blogName + "/post"));
		addAuth(xRequest);
		xRequest->setHttpMethod(KQOAuthRequest::POST);
	}
	KQOAuthParameters params;
	params.insert("type", "text");
	if(title != NULL && !title.isEmpty()) {
		params.insert("title", title);
	}
	params.insert("body", body);
	xRequest->setAdditionalParameters(params);
	return xRequest;
}

KQOAuthRequest* TumblrApi::reblogPost(QString blogName, QString type, QString id, QString reblogKey, QString comment){
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	if(!checkToken()) {
		xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "blog/" + blogName + "/post/reblog"));
		addAuth(xRequest);
		xRequest->setHttpMethod(KQOAuthRequest::POST);
	}
	KQOAuthParameters params;
	params.insert("id", id);
	params.insert("reblog_key", reblogKey);
	params.insert("type", type);
	if(comment != NULL) {
		//params.insert("comment", comment);
	}
	xRequest->setAdditionalParameters(params);
	return xRequest;
}

void TumblrApi::addAuth(KQOAuthRequest* req) {
	req->setConsumerKey(CONSUMER_KEY);
	req->setConsumerSecretKey(CONSUMER_SECRET);
	req->setToken(oauthSettings.value("oauth_token").toString());
	req->setTokenSecret(oauthSettings.value("oauth_token_secret").toString());
}

KQOAuthRequest* TumblrApi::likePost(QString id, QString reblogKey) {
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	if(!checkToken()) {
		xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "user/like"));
		addAuth(xRequest);
		xRequest->setHttpMethod(KQOAuthRequest::POST);
	}
	KQOAuthParameters params;
	params.insert("id", id);
	params.insert("reblog_key", reblogKey);
	xRequest->setAdditionalParameters(params);
	return xRequest;
}

void TumblrApi::logout() {
	oauthSettings.setValue("oauth_token","");
	oauthSettings.setValue("oauth_token_secret","");
}
