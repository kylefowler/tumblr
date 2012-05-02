/*
 * Post.h
 *
 *  Created on: Feb 23, 2012
 *      Author: Kyle
 */

#ifndef POST_H_
#define POST_H_

#include "AbstractObjectBase.h"
#include "Dialogue.h"
#include "VideoPlayer.h"
#include "Photo.h"
#include <QtCore/QStringList>
#include <QtCore>

class Post: public AbstractObjectBase {
public:
	Post();
	virtual ~Post();
	void parse(QVariantMap);
    QString getBlogName() const;
    QString getDate() const;
    QString getFormat() const;
    QString getId() const;
    QString getPostUrl() const;
    QString getReblogKey() const;
    QString getSourceTitle() const;
    QString getSourceUrl() const;
    QStringList getTags() const;
    long getTimestamp() const;
    QString getType() const;
    bool isBookmarklet() const;
    bool isMobile() const;
    void setBlogName(QString blogName);
    void setBookmarklet(bool bookmarklet);
    void setDate(QString date);
    void setFormat(QString format);
    void setId(QString  id);
    void setMobile(bool mobile);
    void setPostUrl(QString postUrl);
    void setReblogKey(QString reblogKey);
    void setSourceTitle(QString sourceTitle);
    void setSourceUrl(QString sourceUrl);
    void setTags(QStringList tags);
    void setTimestamp(long  timestamp);
    void setType(QString type);
    QString getAnswer() const;
    QString getAskingName() const;
    QString getAskingUrl() const;
    QString getBody() const;
    QString getCaption() const;
    QString getDescription() const;
    QList<Dialogue*> getDialogue() const;
    QString getId3Tag() const;
    int getNoteCount() const;
    QList<Photo*> getPhotos() const;
    QString getPlayer() const;
    int getPlays() const;
    QString getQuestion() const;
    QString getSource() const;
    QString getText() const;
    QString getTitle() const;
    QString getUrl() const;
    QList<VideoPlayer*> getVideoPlayer() const;
    void setAnswer(QString answer);
    void setAskingName(QString askingName);
    void setAskingUrl(QString askingUrl);
    void setBody(QString body);
    void setCaption(QString caption);
    void setDescription(QString description);
    void setDialogue(QList<Dialogue*> dialogue);
    void setId3Tag(QString id3Tag);
    void setNoteCount(int noteCount);
    void setPhotos(QList<Photo*> photos);
    void setPlayer(QString player);
    void setPlays(int plays);
    void setQuestion(QString question);
    void setSource(QString source);
    void setText(QString text);
    void setTitle(QString title);
    void setUrl(QString url);
    void setVideoPlayer(QList<VideoPlayer*> videoPlayer);
    bool isLiked() const;
    void setLiked(bool liked);
private:
    QString id;
    QString blogName;
    QString postUrl;
    QString type;
    long timestamp;
    QString date;
    QString format;
    QString reblogKey;
    QStringList tags;
    bool bookmarklet;
    bool mobile;
    bool liked;
    QString sourceUrl;
    QString sourceTitle;
    QString source;
    QString title;
    int noteCount;
    QString body;
    QString caption;
    QList<Photo*> photos;
    QString text;
    QString description;
    QString url;
    QString id3Tag;
    QList<Dialogue*> dialogue;
    QString player;
    QList<VideoPlayer*> videoPlayer;
    int plays;
    QString askingName;
    QString askingUrl;
    QString question;
    QString answer;
};
Q_DECLARE_METATYPE(Post*)
#endif /* POST_H_ */
