/*
 * Blog.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#include "Blog.h"

Blog::Blog() {
}

Blog::~Blog() {
}

void Blog::parse(QVariantMap map) {
	setName(map["name"].toString());
	setTitle(map["title"].toString());
	setUrl(map["url"].toString());
	if(map["tweet"] != NULL) {
		setTweet(map["tweet"].toString());
	}
	if(map["followers"] != NULL) {
		setFollowers(map["followers"].toInt());
	}
	if(map["primary"] != NULL) {
		setPrimary(map["primary"].toBool());
	}
	if(map["ask"] != NULL) {
		setAsk(map["ask"].toBool());
	}
	if(map["ask_anon"] != NULL) {
		setAskAnon(map["ask_anon"].toBool());
	}
	if(map["likes"] != NULL) {
		setLikes(map["likes"].toInt());
	}
	if(map["updated"] != NULL) {
		setUpdated(map["updated"].toLongLong());
	}
	if(map["description"] != NULL) {
		setDescription(map["description"].toString());
	}
	if(map["posts"] != NULL) {
		setPosts(map["posts"].toLongLong());
	}
}

int Blog::getFollowers() const
{
    return followers;
}

QString Blog::getName() const
{
    return name;
}

QString Blog::getTitle() const
{
    return title;
}

QString Blog::getTweet() const
{
    return tweet;
}

QString Blog::getUrl() const
{
    return url;
}

bool Blog::isAdmin() const
{
    return admin;
}

bool Blog::isAsk() const
{
    return ask;
}

bool Blog::isPrimary() const
{
    return primary;
}

void Blog::setAdmin(bool admin)
{
    this->admin = admin;
}

void Blog::setAsk(bool ask)
{
    this->ask = ask;
}

void Blog::setFollowers(int followers)
{
    this->followers = followers;
}

void Blog::setName(QString name)
{
    this->name = name;
}

void Blog::setPrimary(bool primary)
{
    this->primary = primary;
}

void Blog::setTitle(QString title)
{
    this->title = title;
}

void Blog::setTweet(QString tweet)
{
    this->tweet = tweet;
}

void Blog::setUrl(QString url)
{
    this->url = url;
}

QString Blog::getDescription() const
{
    return description;
}

int Blog::getLikes() const
{
    return likes;
}

long Blog::getPosts() const
{
    return posts;
}

long Blog::getUpdated() const
{
    return updated;
}

bool Blog::isAskAnon() const
{
    return askAnon;
}

void Blog::setAskAnon(bool askAnon)
{
    this->askAnon = askAnon;
}

void Blog::setDescription(QString description)
{
    this->description = description;
}

void Blog::setLikes(int likes)
{
    this->likes = likes;
}

void Blog::setPosts(long  posts)
{
    this->posts = posts;
}

void Blog::setUpdated(long  updated)
{
    this->updated = updated;
}





