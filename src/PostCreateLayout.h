/*
 * HomeLayout.h
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#ifndef POSTCREATELAYOUT_H_
#define POSTCREATELAYOUT_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/databinding/qlistdatamodel.h>
#include "Blog.h"
#include "DashboardResponse.h"
#include "RequestEnvelope.h"
#include <bb/cascades/TextField>
#include <bb/cascades/TextArea>
#include "Tumblr.hpp"
#include "AbstractObjectBase.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class ListView;
        class Label;
        class Button;
        class TextField;
        class TextArea;
    }
}

class PostCreateLayout: public bb::cascades::CustomControl
{
	Q_OBJECT
public:
	PostCreateLayout(Blog*);
	virtual ~PostCreateLayout();
private:
	ListView *postTypeList;
	TextField *postTitle;
	TextArea *postContent;
	Button *postButton;
	Blog *blog;
	QVariantListDataModel postTypeModel;
private slots:
	void onPostClicked();
	void onPostComplete(AbstractObjectBase* post);
};

#endif /* POSTCREATELAYOUT_H_ */
