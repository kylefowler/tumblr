/*
 * Photo.h
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#ifndef PHOTO_H_
#define PHOTO_H_

#include "AbstractObjectBase.h"
#include "PhotoSizes.h"

class Photo: public AbstractObjectBase {
public:
	Photo();
	virtual ~Photo();
	void parse(QVariantMap);
    QString getCaption() const;
    QList<PhotoSizes*> getPhotots() const;
    void setCaption(QString caption);
    void setPhotos(QList<PhotoSizes*> photos);
private:
    QString caption;
    QList<PhotoSizes*> photos;
};

#endif /* PHOTO_H_ */
