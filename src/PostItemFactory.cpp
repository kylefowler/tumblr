/*
 * PostItemFactory.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#include "PostItemFactory.h"

PostItemFactory::PostItemFactory() {

}

VisualNode * PostItemFactory::createItem(ListView* list, QString type)
{
    //We only have one item type so we do not need to check the type variable.
    Q_UNUSED(type);
    Q_UNUSED(list);

    PostRenderer *item = new PostRenderer();
    return item;
}

void PostItemFactory::updateItem(ListView* list, VisualNode *control, QString type,
        QVariantList indexPath, QVariant data)
{
    Q_UNUSED(list);
    Q_UNUSED(indexPath);
    Q_UNUSED(type);

    // Update the control with correct data.
    Post* post = data.value<Post*>();
    PostRenderer *item = static_cast<PostRenderer *>(control);
    item->update(post);
}

