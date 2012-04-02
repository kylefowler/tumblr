/*
 * HomeLayout.h
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#ifndef HOMELAYOUT_H_
#define HOMELAYOUT_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/databinding/qlistdatamodel.h>
#include "User.h"
#include "DashboardResponse.h"
#include "RequestEnvelope.h"
#include "Tumblr.hpp"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class ListView;
        class Label;
        class Button;
    }
}

class HomeLayout: public bb::cascades::CustomControl
{
	Q_OBJECT
public:
	HomeLayout(User*);
	virtual ~HomeLayout();
private:
	ListView *blogList;
	Label *blogTitle;
	Label *blogUrl;
	Label *actionStatus;
	Button *logoutButton;
	Button *refreshButton;
	Button *postButton;
	Button *reblogButton;
	Button *likeButton;
	User *user;
	DashboardResponse *dashboard;
	QVariantListDataModel dashboardModel;
private slots:
	void onDashboardDataLoad(AbstractObjectBase*);
	void onLogoutClicked();
	void onRefreshClicked();
	void onPostClicked();
	void onReblogClicked();
	void onLikeClicked();
	void onReblogSuccess(AbstractObjectBase* resp);
	void onLikeSuccess(AbstractObjectBase* resp);
};
#endif /* HOMELAYOUT_H_ */
