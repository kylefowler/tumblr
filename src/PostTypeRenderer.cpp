/*
 * PostRenderer.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#include "PostTypeRenderer.h"

#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DockLayoutProperties>
#include <bb/cascades/animation/translatetransition.h>

PostTypeRenderer::PostTypeRenderer() :
	CustomControl()
{
	Container *itemContainer = new Container();

	    // Dock layout with margins inside.
	    DockLayout *itemLayout = new DockLayout();
	    itemLayout->setChildMarginsPolicy(ChildMarginsPolicy::FitInsideParent);
	    itemContainer->setLayout(itemLayout);
	    itemContainer->setPreferredWidth(300);

	    // A list item label, docked to the bottom, the text is set in updateItem.
	    postType = Label::create()
	        .text(" ")
	        .layoutProperties(DockLayoutProperties::create()
	        .horizontal(HorizontalAlignment::Center)
	        .vertical(VerticalAlignment::Bottom))
	        .bottomMargin(10.0f)
	        .leftMargin(10.0f)
	        .textColor(Color::White);

	    // Add the three controls to the item container.
	    //itemContainer->add(imageContainer);
	    itemContainer->add(postType);

	    setRoot(itemContainer);
}

void PostTypeRenderer::update(QString type)
{
	postType->setText(type);
}

void PostTypeRenderer::select(bool select)
{
    // When the item is selected, shift it 10px, on unselected shift it back.
    if (select) {
    	TranslateTransition* anim = TranslateTransition::create(this).toX(15);
		anim->play();
    } else {
    	TranslateTransition* anim = TranslateTransition::create(this).toX(0);
    	anim->play();
    }
}

void PostTypeRenderer::reset(bool selected, bool activated)
{
    Q_UNUSED(activated);

    // Since items are recycled the reset function is where we have
    // to make sure that item state, defined by the arguments, is correct.
    select(selected);
}

void PostTypeRenderer::activate(bool activate)
{
    // We do not do anything with the item when it becomes active.
    Q_UNUSED(activate);
}

