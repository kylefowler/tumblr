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
	VisualNode * createItem(ListView* list, const QString &type);
    void updateItem(ListView* list, bb::cascades::VisualNode *listItem,
            const QString &type, const QVariantList &indexPath, const QVariant &data);
};

#endif /* POSTITEMFACTORY_H_ */
