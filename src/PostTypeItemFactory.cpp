/*
 * PostItemFactory.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#include "PostTypeItemFactory.h"

PostTypeItemFactory::PostTypeItemFactory() {

}

VisualNode * PostTypeItemFactory::createItem(ListView* list, const QString &type)
{
    //We only have one item type so we do not need to check the type variable.
    Q_UNUSED(type);
    Q_UNUSED(list);

    PostTypeRenderer *item = new PostTypeRenderer();
    return item;
}

void PostTypeItemFactory::updateItem(ListView* list, bb::cascades::VisualNode *listItem,
        const QString &type, const QVariantList &indexPath, const QVariant &data)
{
    Q_UNUSED(list);
    Q_UNUSED(indexPath);
    Q_UNUSED(type);

    // Update the control with correct data.
    QString postType = data.value<QString>();
    PostTypeRenderer *item = static_cast<PostTypeRenderer *>(listItem);
    item->update(postType);
}

