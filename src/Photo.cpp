/*
 * Photo.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#include "Photo.h"

Photo::Photo() {
}

Photo::~Photo() {
}

void Photo::parse(QVariantMap map) {
	if(map["caption"] != NULL) {
		setCaption(map["caption"].toString());
	}
	QList<QVariant> photoList = map["alt_sizes"].toList();
	foreach(const QVariant &b, photoList) {
		PhotoSizes *p = new PhotoSizes();
		p->parse(b.toMap());
		photos.append(p);
	}
}

QString Photo::getCaption() const
{
    return caption;
}

QList<PhotoSizes*> Photo::getPhotots() const
{
    return photos;
}

void Photo::setCaption(QString caption)
{
    this->caption = caption;
}

void Photo::setPhotos(QList<PhotoSizes*> photos)
{
    this->photos = photos;
}



