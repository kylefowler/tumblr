/*
 * RequestEnvelope.cpp
 *
 *  Created on: Feb 19, 2012
 *      Author: Kyle
 */

#include "RequestEnvelope.h"

RequestEnvelope::RequestEnvelope(ApiResponseObjectFactory::ApiType type,KQOAuthRequest* apiRequest) {
	response = new ApiResponse(type);
	request = apiRequest;
}

RequestEnvelope::~RequestEnvelope() {
	delete request;
}

KQOAuthRequest* RequestEnvelope::getRequest() {
	return request;
}

void RequestEnvelope::makeRequest() {
	connect(TumblrApi::instance()->getRequestManager(), SIGNAL(authorizedRequestReady(QByteArray,int)), this, SLOT(onRequestCallback(QByteArray,int)));
	TumblrApi::instance()->getRequestManager()->executeAuthorizedRequest(request, 0);
}

void RequestEnvelope::onRequestCallback(QByteArray resp, int id) {
	disconnect(TumblrApi::instance()->getRequestManager(), SIGNAL(authorizedRequestReady(QByteArray,int)), this, SLOT(onRequestCallback(QByteArray, int)));
	response->parse(resp);
	qDebug() << resp;
	if(response->getMeta() == NULL) {
		return;
	}
	if(response->getMeta()->getStatus() == 200) {
		emit requestComplete(response->getResponse());
	} else {
		emit requestError(response->getMeta());
	}
}
