/*
 * DashboardResponse.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#include "DashboardResponse.h"

DashboardResponse::DashboardResponse() {
}

DashboardResponse::~DashboardResponse() {
}

void DashboardResponse::parse(QVariantMap map) {
	QList<QVariant> postList = map["posts"].toList();
	foreach(const QVariant &b, postList) {
		Post *p = new Post();
		p->parse(b.toMap());
		posts.append(p);
	}
}

QList<Post*> DashboardResponse::getPosts() const
{
    return posts;
}

void DashboardResponse::setPosts(QList<Post*> posts)
{
    this->posts = posts;
}



