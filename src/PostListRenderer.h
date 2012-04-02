/*
 * PostRenderer.h
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#ifndef POSTLISTRENDERER_H_
#define POSTLISTRENDERER_H_

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
        class TextArea;
    }
}

class PostListRenderer: public bb::cascades::CustomControl, public ListItemListener {
public:
	PostListRenderer();
	void update(Post* post);
    void select(bool select);
    void reset(bool selected, bool activated);
    void activate(bool activate);
private:
    Label* postTitle;
    TextArea* postBody;
    Label* postingUser;
    Label* rebloggedUser;
    ImageView* pic;
    Post* itemPost;
private slots:
	void onReblogClicked();
	void onLikeClicked();
};

#endif /* POSTRENDERER_H_ */
