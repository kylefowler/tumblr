/*
 * PostItemFactory.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#include "PostItemFactory.h"



PostItemFactory::PostItemFactory() {

}

VisualNode * PostItemFactory::createItem(ListView* list, const QString &type)
{
    //We only have one item type so we do not need to check the type variable.
    Q_UNUSED(type);
    Q_UNUSED(list);

    PostListRenderer *item = new PostListRenderer();
    return item;
}

void PostItemFactory::updateItem(ListView* list, bb::cascades::VisualNode *listItem,
        const QString &type, const QVariantList &indexPath, const QVariant &data)
{
    Q_UNUSED(list);
    Q_UNUSED(indexPath);
    Q_UNUSED(type);

    // Update the control with correct data.
    Post* post = data.value<Post*>();
    PostListRenderer *item = static_cast<PostListRenderer *>(listItem);
    item->update(post);
}

