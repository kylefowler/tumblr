/*
 * PhotoSizes.h
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#ifndef PHOTOSIZES_H_
#define PHOTOSIZES_H_

#include "AbstractObjectBase.h"

class PhotoSizes: public AbstractObjectBase {
public:
	PhotoSizes();
	virtual ~PhotoSizes();
	void parse(QVariantMap);
    int getHeight() const;
    QString getUrl() const;
    int getWidth() const;
    void setHeight(int height);
    void setUrl(QString url);
    void setWidth(int width);
private:
	int width;
	int height;
	QString url;
};

#endif /* PHOTOSIZES_H_ */
