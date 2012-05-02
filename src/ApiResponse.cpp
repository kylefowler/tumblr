/*
 * ApiResponse.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#include "ApiResponse.h"
#include <QtCore/QVariant>
#include <QtCore/QVariantMap>
#include <QtCore>
#include "json.h"
#include <bb/data/DataSet>
#include <bb/data/JsonDataAccess>

ApiResponse::ApiResponse(ApiResponseObjectFactory::ApiType targetType) {
	response = ApiResponseObjectFactory::createApiResponseObject(targetType);
	type = targetType;
}

ApiResponse::~ApiResponse() {
}

AbstractObjectBase* ApiResponse::getResponse() {
	return response;
}

ResponseMeta* ApiResponse::getMeta() {
	return meta;
}

ApiResponseObjectFactory::ApiType ApiResponse::getType() {
	return type;
}

void ApiResponse::parse(QByteArray data) {
	QString jData(data);
	QVariantMap resp = QtJson::Json::parse(jData).toMap();
	foreach(const QString &key, resp.keys()) {
		QVariantMap v = resp[key].toMap();
		if(key == "meta") {
			meta = new ResponseMeta();
			meta->parse(v);
		} else {
			if(response != NULL) {
				response->parse(v);
			}
		}
	}
}
