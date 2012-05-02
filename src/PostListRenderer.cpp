/*
 * PostRenderer.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: Kyle
 */

#include "PostListRenderer.h"

#include <bb/cascades/ImageView>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/TextArea>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DockLayoutProperties>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>
#include <bb/cascades/animation/translatetransition.h>
#include "oauth/KQOAuthRequest.h"
#include "RequestEnvelope.h"

PostListRenderer::PostListRenderer() :
	CustomControl()
{
	//stack container
	Container *itemContainer = new Container();
	StackLayout *itemLayout = StackLayout::create().direction(LayoutDirection::TopToBottom);
	itemContainer->setLayout(itemLayout);
	itemContainer->setPreferredWidth(800.0f);

	Container *topContainer = new Container();
	StackLayout *topLayout = StackLayout::create().direction(LayoutDirection::LeftToRight);
	topContainer->setLayout(topLayout);
	topContainer->setPreferredSize(800.0f, 25.0f);

    postingUser = Label::create(" ")
    					.rightMargin(10.0f)
    					.layoutProperties(DockLayoutProperties::create()
							.horizontal(HorizontalAlignment::Center)
							.vertical(VerticalAlignment::Top));
    rebloggedUser = Label::create(" ")
    	    				.layoutProperties(DockLayoutProperties::create()
    								.horizontal(HorizontalAlignment::Center)
    								.vertical(VerticalAlignment::Top));

    topContainer->add(postingUser);
    topContainer->add(rebloggedUser);


	// The list item image, docked to the top, the actual image is set in updateItem.
	//pic = ImageView::create("").preferredSize(250.0f, 168.0f);

	// A list item label, docked to the bottom, the text is set in updateItem.
	postTitle = Label::create()
		.text(" ")
		.layoutProperties(DockLayoutProperties::create()
		.horizontal(HorizontalAlignment::Center)
		.vertical(VerticalAlignment::Top))
		.bottomMargin(5.0f);
	postTitle->setPreferredSize(750.0f,250.f);

    postBody = TextArea::create().layoutProperties(DockLayoutProperties::create()
				.horizontal(HorizontalAlignment::Center)
				.vertical(VerticalAlignment::Top));
    postBody->setText("");
    postBody->setPreferredWidth(750.0f);
    postBody->setEditable(false);
    postBody->setBackgroundVisible(false);
    postBody->setEnabled(false);

	// Add the three controls to the item container.
    itemContainer->add(topContainer);
	itemContainer->add(postTitle);
	itemContainer->add(postBody);

	setRoot(itemContainer);
}

void PostListRenderer::update(Post* post)
{
	itemPost = post;

	postingUser->setText(post->getBlogName());
	if(post->getSourceTitle().isEmpty()) {
		rebloggedUser->setText("");
		rebloggedUser->setVisible(false);
	} else {
		rebloggedUser->setText(post->getSourceTitle());
		rebloggedUser->setVisible(true);
	}
	if(post->getTitle().isEmpty()) {
		postTitle->setVisible(false);
	} else {
		postTitle->setVisible(true);
		postTitle->setText(post->getTitle());
	}

	if(post->getType() == "photo") {
		//pic->setImage(Image::get(post->getPhotos().at(0)->getPhotots().at(0)->getUrl()));
		postBody->setText(post->getCaption());
	} else {
		postBody->setText(post->getBody());
	}
	if(postBody->text().isEmpty()) {
		postBody->setVisible(false);
	} else {
		postBody->setVisible(true);
	}
}

void PostListRenderer::select(bool select)
{
    // When the item is selected, shift it 10px, on unselected shift it back.
    if (select) {
		TranslateTransition* anim = TranslateTransition::create(this).toX(20.0f).autoDeleted(true);
		anim->play();
    } else {
		TranslateTransition* anim = TranslateTransition::create(this).toX(0.0f).autoDeleted(true);
		anim->play();
    }
}

void PostListRenderer::reset(bool selected, bool activated)
{
    Q_UNUSED(activated);

    // Since items are recycled the reset function is where we have
    // to make sure that item state, defined by the arguments, is correct.
    select(selected);
}

void PostListRenderer::activate(bool activate)
{
    // We do not do anything with the item when it becomes active.
    Q_UNUSED(activate);
}
