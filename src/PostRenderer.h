/*
 * PostRenderer.h
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#ifndef POSTRENDERER_H_
#define POSTRENDERER_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/ListItemListener>
#include "Post.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class ImageView;
        class Label;
    }
}

class PostRenderer: public bb::cascades::CustomControl, public ListItemListener {
public:
	PostRenderer();
	void update(Post* post);
    void select(bool select);
    void reset(bool selected, bool activated);
    void activate(bool activate);
private:
    Label* postTitle;
    ImageView* pic;
};

#endif /* POSTRENDERER_H_ */
