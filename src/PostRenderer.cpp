/*
 * PostRenderer.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#include "PostRenderer.h"

#include <bb/cascades/ImageView>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DockLayoutProperties>
#include <bb/cascades/animation/rotatetransition.h>

PostRenderer::PostRenderer() :
	CustomControl()
{
	Container *itemContainer = new Container();

	    // Dock layout with margins inside.
	    DockLayout *itemLayout = new DockLayout();
	    itemLayout->setChildMarginsPolicy(ChildMarginsPolicy::FitInsideParent);
	    itemContainer->setLayout(itemLayout);
	    itemContainer->setPreferredWidth(300);

	    // The list item image, docked to the top, the actual image is set in updateItem.
	    pic = ImageView::create("").preferredSize(250.0f, 168.0f);

	    // Temporary put the image in a container to get top margins working (will be )
	    Container *imageContainer = Container::create()
	                                    .layoutProperties(DockLayoutProperties::create()
	                                    .horizontal(HorizontalAlignment::Center))
	                                    .topMargin(5.0f);
	    //imageContainer->add(pic);

	    // A list item label, docked to the bottom, the text is set in updateItem.
	    postTitle = Label::create()
	        .text(" ")
	        .layoutProperties(DockLayoutProperties::create()
	        .horizontal(HorizontalAlignment::Center)
	        .vertical(VerticalAlignment::Bottom))
	        .bottomMargin(10.0f)
	        .textColor(Color::White);

	    // Add the three controls to the item container.
	    //itemContainer->add(imageContainer);
	    itemContainer->add(postTitle);

	    setRoot(itemContainer);
}

void PostRenderer::update(Post* post)
{
	postTitle->setText(post->getTitle());
	if(post->getType() == "photo") {
		qDebug() << post->getPhotos().at(0)->getPhotots().at(0)->getUrl();
		if(post->getTitle().isEmpty()) {
			postTitle->setText(post->getPhotos().at(0)->getPhotots().at(0)->getUrl());
		}
		pic->setImage(Image::get(post->getPhotos().at(0)->getPhotots().at(0)->getUrl()));
	}
}

void PostRenderer::select(bool select)
{
    // When the item is selected, shift it 10px, on unselected shift it back.
    if (select) {
		RotateTransition* anim = RotateTransition::create(this).duration(300).fromAngleZ(0).toAngleZ(360).autoDeleted(true);
		anim->play();
    } else {
    	RotateTransition* anim = RotateTransition::create(this).duration(300).fromAngleZ(360).toAngleZ(0).autoDeleted(true);
    	anim->play();
    }
}

void PostRenderer::reset(bool selected, bool activated)
{
    Q_UNUSED(activated);

    // Since items are recycled the reset function is where we have
    // to make sure that item state, defined by the arguments, is correct.
    select(selected);
}

void PostRenderer::activate(bool activate)
{
    // We do not do anything with the item when it becomes active.
    Q_UNUSED(activate);
}

