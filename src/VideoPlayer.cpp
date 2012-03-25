/*
 * VideoPlayer.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#include "VideoPlayer.h"

VideoPlayer::VideoPlayer() {
}

VideoPlayer::~VideoPlayer() {
}

QString VideoPlayer::getEmbedCode() const
{
    return embedCode;
}

int VideoPlayer::getWidth() const
{
    return width;
}

void VideoPlayer::setEmbedCode(QString embedCode)
{
    this->embedCode = embedCode;
}

void VideoPlayer::parse(QVariantMap qMap)
{
	setWidth(qMap["width"].toInt());
	setEmbedCode(qMap["embed_code"].toString());
}

void VideoPlayer::setWidth(int width)
{
    this->width = width;
}



