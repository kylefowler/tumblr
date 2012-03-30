/*
 * PostTypeItemFactory.h
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#ifndef POSTTYPEITEMFACTORY_H_
#define POSTTYPEITEMFACTORY_H_

#include <bb/cascades/ListItemManager>
#include "PostTypeRenderer.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class ListView;
    }
}

class PostTypeItemFactory: public bb::cascades::ListItemManager {
public:
	PostTypeItemFactory();
	VisualNode * createItem(ListView* list, QString type);
    void updateItem(ListView* list, VisualNode *control, QString type, QVariantList indexPath,
            QVariant data);
};

#endif /* POSTITEMFACTORY_H_ */
