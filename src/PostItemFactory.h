/*
 * PostItemFactory.h
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#ifndef POSTITEMFACTORY_H_
#define POSTITEMFACTORY_H_

#include <bb/cascades/ListItemManager>
#include "PostListRenderer.h"
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

    /**
     * Creates a VisualNode for list to be used as a list item.
     *
     * @param list ListView for which the item should be created.
     * @param type List item type, the cookbook only have one type of item.
     */
    VisualNode * createItem(ListView* list, const QString &type);

    /**
     * Update listItem based on the provided type, indexPath and data.
     *
     * This function is called whenever an item is about to be shown, and also
     * when the data representation of the item (in the DataModel) has changed.
     *
     * @param list ListView holding the item to be updated.
     * @param control List item to be updated.
     * @param type List item type, the cookbook only have one type of item
     * @param indexPath Index path to the item that is to be updated.
     * @param data Data from the DataModel that corresponds to listItem.
     */
    void updateItem(ListView* list, VisualNode *listItem, const QString &type,
            const QVariantList &indexPath, const QVariant &data);
};

#endif /* POSTITEMFACTORY_H_ */
