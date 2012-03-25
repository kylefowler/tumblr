/*
 * PostItemFactory.h
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#ifndef POSTITEMFACTORY_H_
#define POSTITEMFACTORY_H_

#include <bb/cascades/ListItemManager>
#include "PostRenderer.h"
#include "Post.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class ListView;
    }
}

class PostItemFactory: public bb::cascades::ListItemManager {
public:
	PostItemFactory();
	VisualNode * createItem(ListView* list, QString type);
    void updateItem(ListView* list, VisualNode *control, QString type, QVariantList indexPath,
            QVariant data);
};

#endif /* POSTITEMFACTORY_H_ */
