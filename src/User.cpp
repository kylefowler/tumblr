/*
 * User.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#include "User.h"

User::User() {
}

User::~User() {
}

void User::parse(QVariantMap qMap)
{
	QVariantMap map(qMap["user"].toMap());
	setName(map["name"].toString());
	setLikes(map["likes"].toInt());
	setFollowing(map["following"].toInt());
	setDefaultPostFormat(map["default_post_format"].toString());
	QList<QVariant> blogList = map["blogs"].toList();
	foreach(const QVariant &b, blogList) {
		Blog *bl = new Blog();
		bl->parse(b.toMap());
		blogs.append(bl);
	}
}

QString User::getName()
{
	return name;
}

int User::getLikes()
{
	return likes;
}

int User::getFollowing()
{
	return following;
}

QString User::getDefaultPostFormat()
{
	return defaultPostFormat;
}

QList<Blog*> User::getBlogs()
{
	return blogs;
}

void User::setBlogs(QList<Blog*> blogs)
{
    this->blogs = blogs;
}

void User::setDefaultPostFormat(QString defaultPostFormat)
{
    this->defaultPostFormat = defaultPostFormat;
}

void User::setFollowing(int following)
{
    this->following = following;
}

void User::setLikes(int likes)
{
    this->likes = likes;
}

void User::setName(QString name)
{
    this->name = name;
}
