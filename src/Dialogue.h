/*
 * Dialogue.h
 *
 *  Created on: Feb 24, 2012
 *      Author: Kyle
 */

#ifndef DIALOGUE_H_
#define DIALOGUE_H_

#include "AbstractObjectBase.h"

class Dialogue: public AbstractObjectBase {
public:
	Dialogue();
	virtual ~Dialogue();
    void parse(QVariantMap);
    QString getLabel() const;
    QString getName() const;
    QString getPhrase() const;
    void setLabel(QString label);
    void setName(QString name);
    void setPhrase(QString phrase);
private:
    QString label;
    QString name;
    QString phrase;
};

#endif /* DIALOGUE_H_ */
