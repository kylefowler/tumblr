/*
 * PostRenderer.h
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#ifndef POSTTYPERENDERER_H_
#define POSTTYPERENDERER_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/ListItemListener>
#include "Post.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Label;
    }
}

class PostTypeRenderer: public bb::cascades::CustomControl, public ListItemListener {
public:
	PostTypeRenderer();
	void update(QString type);
    void select(bool select);
    void reset(bool selected, bool activated);
    void activate(bool activate);
private:
    Label* postType;
};

#endif /* POSTRENDERER_H_ */
