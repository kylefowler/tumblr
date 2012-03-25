/*
 * VideoPlayer.h
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#ifndef VIDEOPLAYER_H_
#define VIDEOPLAYER_H_

#include "AbstractObjectBase.h"

class VideoPlayer: public AbstractObjectBase {
public:
	VideoPlayer();
	virtual ~VideoPlayer();
    void parse(QVariantMap);
    QString getEmbedCode() const;
    int getWidth() const;
    void setEmbedCode(QString embedCode);
    void setWidth(int width);
private:
    int width;
    QString embedCode;
};

#endif /* VIDEOPLAYER_H_ */
