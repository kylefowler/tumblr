/*
 * User.h
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#ifndef USER_H_
#define USER_H_

#include "AbstractObjectBase.h"
#include <QtCore>
#include <QtCore/QList>
#include "qlist.h"
#include "Blog.h"

class User: public AbstractObjectBase {
public:
	User();
	virtual ~User();
	void parse(QVariantMap);
	QString getName();
	int getLikes();
	int getFollowing();
	QString getDefaultPostFormat();
	QList<Blog*> getBlogs();
    void setBlogs(QList<Blog*> blogs);
    void setDefaultPostFormat(QString defaultPostFormat);
    void setFollowing(int following);
    void setLikes(int likes);
    void setName(QString name);
private:
	QString name;
	int likes;
	int following;
	QString defaultPostFormat;
	QList<Blog*> blogs;
};

#endif /* USER_H_ */
