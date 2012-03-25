/*
 * DashboardResponse.h
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#ifndef DASHBOARDRESPONSE_H_
#define DASHBOARDRESPONSE_H_

#include "AbstractObjectBase.h"
#include "Post.h"

class DashboardResponse: public AbstractObjectBase {
public:
	DashboardResponse();
	virtual ~DashboardResponse();
    void parse(QVariantMap);
    QList<Post*> getPosts() const;
    void setPosts(QList<Post*> posts);
private:
    QList<Post*> posts;
};

#endif /* DASHBOARDRESPONSE_H_ */
