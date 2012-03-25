/*
 * PhotoSizes.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#include "PhotoSizes.h"

PhotoSizes::PhotoSizes() {

}

PhotoSizes::~PhotoSizes() {
}

void PhotoSizes::parse(QVariantMap map) {
	setWidth(map["width"].toInt());
	setHeight(map["height"].toInt());
	setUrl(map["url"].toString());
}

int PhotoSizes::getHeight() const
{
    return height;
}

QString PhotoSizes::getUrl() const
{
    return url;
}

int PhotoSizes::getWidth() const
{
    return width;
}

void PhotoSizes::setHeight(int height)
{
    this->height = height;
}

void PhotoSizes::setUrl(QString url)
{
    this->url = url;
}

void PhotoSizes::setWidth(int width)
{
    this->width = width;
}



