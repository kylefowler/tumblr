/*
 * Post.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: Kyle
 */

#include "Post.h"

Post::Post() {
}

Post::~Post() {
}

Q_INVOKABLE QString Post::getTitleText() {
	if(title.isEmpty()) {
		return "Test Title";
	}
	return title;
}

void Post::parse(QVariantMap map) {
	setBlogName(map["blog_name"].toString());
	setId(map["id"].toString());
	setPostUrl(map["post_url"].toString());
	setType(map["type"].toString());
	setDate(map["date"].toString());
	setTimestamp(map["timestamp"].toLongLong());
	setFormat(map["format"].toString());
	setReblogKey(map["reblog_key"].toString());
	setNoteCount(map["note_count"].toInt());
	QStringList blogList = map["blogs"].toStringList();
	foreach(const QString &tag, blogList) {
		tags.append(tag);
	}
	if(map.contains("title")){
		setTitle(map["title"].toString());
	}
	if(map.contains("body")){
		setBody(map["body"].toString());
	}
	if(map.contains("photos")){
		QList<QVariant> photoList = map["photos"].toList();
		foreach(const QVariant &b, photoList) {
			Photo *p = new Photo();
			p->parse(b.toMap());
			photos.append(p);
		}
	}
	if(map.contains("caption")){
		setCaption(map["caption"].toString());
	}
	if(map.contains("text")){
		setText(map["text"].toString());
	}
	if(map.contains("source")){
		setTitle(map["source"].toString());
	}
	if(map.contains("url")){
		setUrl(map["url"].toString());
	}
	if(map.contains("description")){
		setDescription(map["description"].toString());
	}
	if(map.contains("source_url")){
		setUrl(map["source_url"].toString());
	}
	if(map.contains("source_title")){
		setUrl(map["source_title"].toString());
	}
	if(map.contains("dialogue")){
		QList<QVariant> dialogueList = map["dialogue"].toList();
		foreach(const QVariant &d, dialogueList) {
			Dialogue *d1 = new Dialogue();
			d1->parse(d.toMap());
			dialogue.append(d1);
		}
	}
	if(map.contains("player")){
		if(getType() == "audio") {
			setPlayer(map["player"].toString());
		} else {
			QList<QVariant> vpList = map["player"].toList();
			foreach(const QVariant &d, vpList) {
				VideoPlayer *d1 = new VideoPlayer();
				d1->parse(d.toMap());
				videoPlayer.append(d1);
			}
		}
	}
	if(map.contains("plays")){
		setPlays(map["plays"].toInt());
	}
	if(map.contains("id3_title")){
		setId3Tag(map["id3_title"].toString());
	}
	if(map.contains("asking_name")){
		setAskingName(map["asking_name"].toString());
	}
	if(map.contains("asking_url")){
		setAskingUrl(map["asking_url"].toString());
	}
	if(map.contains("question")){
		setQuestion(map["question"].toString());
	}
	if(map.contains("answer")){
		setAnswer(map["answer"].toString());
	}
	if(map.contains("mobile")) {
		setMobile(map["mobile"].toBool());
	}
	if(map.contains("bookmarklet")) {
		setBookmarklet(map["bookmarklet"].toBool());
	}
	if(map.contains("liked")) {
		setLiked(map["liked"].toBool());
	}
}

QString Post::getBlogName() const
{
    return blogName;
}

QString Post::getDate() const
{
    return date;
}

QString Post::getFormat() const
{
    return format;
}

QString Post::getId() const
{
    return id;
}

QString Post::getPostUrl() const
{
    return postUrl;
}

QString Post::getReblogKey() const
{
    return reblogKey;
}

QString Post::getSourceTitle() const
{
    return sourceTitle;
}

QString Post::getSourceUrl() const
{
    return sourceUrl;
}

QStringList Post::getTags() const
{
    return tags;
}

long Post::getTimestamp() const
{
    return timestamp;
}

QString Post::getType() const
{
    return type;
}

bool Post::isBookmarklet() const
{
    return bookmarklet;
}

bool Post::isMobile() const
{
    return mobile;
}

void Post::setBlogName(QString blogName)
{
    this->blogName = blogName;
}

void Post::setBookmarklet(bool bookmarklet)
{
    this->bookmarklet = bookmarklet;
}

void Post::setDate(QString date)
{
    this->date = date;
}

void Post::setFormat(QString format)
{
    this->format = format;
}

void Post::setId(QString  id)
{
    this->id = id;
}

void Post::setMobile(bool mobile)
{
    this->mobile = mobile;
}

void Post::setPostUrl(QString postUrl)
{
    this->postUrl = postUrl;
}

void Post::setReblogKey(QString reblogKey)
{
    this->reblogKey = reblogKey;
}

void Post::setSourceTitle(QString sourceTitle)
{
    this->sourceTitle = sourceTitle;
}

void Post::setSourceUrl(QString sourceUrl)
{
    this->sourceUrl = sourceUrl;
}

void Post::setTags(QStringList tags)
{
    this->tags = tags;
}

void Post::setTimestamp(long  timestamp)
{
    this->timestamp = timestamp;
}

void Post::setType(QString type)
{
    this->type = type;
}

QString Post::getAnswer() const
{
    return answer;
}

QString Post::getAskingName() const
{
    return askingName;
}

QString Post::getAskingUrl() const
{
    return askingUrl;
}

QString Post::getBody() const
{
    return body;
}

QString Post::getCaption() const
{
    return caption;
}

QString Post::getDescription() const
{
    return description;
}

QList<Dialogue*> Post::getDialogue() const
{
    return dialogue;
}

QString Post::getId3Tag() const
{
    return id3Tag;
}

int Post::getNoteCount() const
{
    return noteCount;
}

QList<Photo*> Post::getPhotos() const
{
    return photos;
}

QString Post::getPlayer() const
{
    return player;
}

int Post::getPlays() const
{
    return plays;
}

QString Post::getQuestion() const
{
    return question;
}

QString Post::getSource() const
{
    return source;
}

QString Post::getText() const
{
    return text;
}

QString Post::getTitle() const
{
    return title;
}

QString Post::getUrl() const
{
    return url;
}

QList<VideoPlayer*> Post::getVideoPlayer() const
{
    return videoPlayer;
}

void Post::setAnswer(QString answer)
{
    this->answer = answer;
}

void Post::setAskingName(QString askingName)
{
    this->askingName = askingName;
}

void Post::setAskingUrl(QString askingUrl)
{
    this->askingUrl = askingUrl;
}

void Post::setBody(QString body)
{
    this->body = body;
}

void Post::setCaption(QString caption)
{
    this->caption = caption;
}

void Post::setDescription(QString description)
{
    this->description = description;
}

void Post::setDialogue(QList<Dialogue*> dialogue)
{
    this->dialogue = dialogue;
}

void Post::setId3Tag(QString id3Tag)
{
    this->id3Tag = id3Tag;
}

void Post::setNoteCount(int noteCount)
{
    this->noteCount = noteCount;
}

void Post::setPhotos(QList<Photo*> photos)
{
    this->photos = photos;
}

void Post::setPlayer(QString player)
{
    this->player = player;
}

void Post::setPlays(int plays)
{
    this->plays = plays;
}

void Post::setQuestion(QString question)
{
    this->question = question;
}

void Post::setSource(QString source)
{
    this->source = source;
}

void Post::setText(QString text)
{
    this->text = text;
}

void Post::setTitle(QString title)
{
    this->title = title;
}

void Post::setUrl(QString url)
{
    this->url = url;
}

void Post::setVideoPlayer(QList<VideoPlayer*> videoPlayer)
{
    this->videoPlayer = videoPlayer;
}

bool Post::isLiked() const
{
    return liked;
}

void Post::setLiked(bool liked)
{
    this->liked = liked;
}
