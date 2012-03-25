/*
 * TumblrApi.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef TUMBLRAPI_H_
#define TUMBLRAPI_H_

#include <iostream>
#include <QtCore>
#include <QtCore/QObject>
#include <QSettings>
#include <oauth/kqoauthmanager.h>
#include <oauth/kqoauthrequest_xauth.h>
#include <oauth/kqoauthrequest.h>

class TumblrApi : public QObject {
	Q_OBJECT
public:
	static const QString API_BASE;
	static TumblrApi* instance();
	void xauth(QString,QString);
	void getAccess();
    void logout();
	bool checkToken();
	KQOAuthManager* getRequestManager();

	//api methods
	KQOAuthRequest* getUserInfo();
	KQOAuthRequest* getUserDashboard(int,int,QString,long,bool,bool);
	KQOAuthRequest* getUserLikes();
	KQOAuthRequest* getUserFollowing();
	KQOAuthRequest* followBlog(QString);
	KQOAuthRequest* unfollowBlog(QString);
	KQOAuthRequest* likePost(int,QString);
	KQOAuthRequest* unlikePost(int,QString);
	KQOAuthRequest* getBlogInfo(QString);
	KQOAuthRequest* getBlogAvatar(QString);
	KQOAuthRequest* getBlogFollowers(QString);
	KQOAuthRequest* getBlogPosts(QString);
	KQOAuthRequest* getBlogPostDrafts(QString);
	KQOAuthRequest* makePost(QString,QString,QString,QString,QString,QString,QString);
	KQOAuthRequest* deletePost(QString);
private:
	TumblrApi();
	virtual ~TumblrApi();
	static const QString CONSUMER_KEY;
	static const QString CONSUMER_SECRET;
	static TumblrApi* m_instance;
    KQOAuthManager *oauthManager;
    KQOAuthRequest *oauthRequest;
    QSettings oauthSettings;

signals:
	void loginComplete(bool);

private slots:
	void onTemporaryTokenReceived(QString temporaryToken, QString temporaryTokenSecret);
	void onAuthorizationReceived(QString token, QString verifier);
	void onAccessTokenReceived(QString token, QString tokenSecret);
	void onAuthorizedRequestDone();
	void onRequestReady(QByteArray);
};

#endif /* TUMBLRAPI_H_ */
