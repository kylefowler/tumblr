/*
 * Dialogue.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#include "Dialogue.h"

Dialogue::Dialogue() {

}

Dialogue::~Dialogue() {
}

void Dialogue::parse(QVariantMap map) {
	setLabel(map["label"].toString());
	setName(map["name"].toString());
	setPhrase(map["phrase"].toString());
}

QString Dialogue::getLabel() const
{
    return label;
}

QString Dialogue::getName() const
{
    return name;
}

QString Dialogue::getPhrase() const
{
    return phrase;
}

void Dialogue::setLabel(QString label)
{
    this->label = label;
}

void Dialogue::setName(QString name)
{
    this->name = name;
}

void Dialogue::setPhrase(QString phrase)
{
    this->phrase = phrase;
}



