/*
 * Blog.h
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#ifndef BLOG_H_
#define BLOG_H_

#include "AbstractObjectBase.h"

class Blog: public AbstractObjectBase {
public:
	Blog();
	virtual ~Blog();
	void parse(QVariantMap);
    int getFollowers() const;
    QString getName() const;
    QString getTitle() const;
    QString getTweet() const;
    QString getUrl() const;
    bool isAdmin() const;
    bool isAsk() const;
    bool isPrimary() const;
    void setAdmin(bool admin);
    void setAsk(bool ask);
    void setFollowers(int followers);
    void setName(QString name);
    void setPrimary(bool primary);
    void setTitle(QString title);
    void setTweet(QString tweet);
    void setUrl(QString url);
    QString getDescription() const;
    int getLikes() const;
    long getPosts() const;
    long getUpdated() const;
    bool isAskAnon() const;
    void setAskAnon(bool askAnon);
    void setDescription(QString description);
    void setLikes(int likes);
    void setPosts(long  posts);
    void setUpdated(long  updated);
private:
	QString name;
	QString url;
	int followers;
	int likes;
	long updated;
	long posts;
	QString description;
	bool primary;
	QString title;
	bool admin;
	bool ask;
	bool askAnon;
	QString tweet;
};

#endif /* BLOG_H_ */
