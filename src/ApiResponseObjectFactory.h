/*
 * ApiResponseObjectFactory.h
 *
 *  Created on: Feb 19, 2012
 *      Author: Kyle
 */

#ifndef APIRESPONSEOBJECTFACTORY_H_
#define APIRESPONSEOBJECTFACTORY_H_

#include "AbstractObjectBase.h"
#include "ResponseMeta.h"
#include "User.h"
#include "DashboardResponse.h"

class ApiResponseObjectFactory {
public:
	enum ApiType { ResponseMetaObj, UserObj, DashboardObj };

	ApiResponseObjectFactory();
	virtual ~ApiResponseObjectFactory();
	static AbstractObjectBase* createApiResponseObject(ApiType type) {
		switch(type) {
		default:
		case ResponseMetaObj:
			return new ResponseMeta;
		case UserObj:
			return new User;
		case DashboardObj:
			return new DashboardResponse;
		}
	}
};

#endif /* APIRESPONSEOBJECTFACTORY_H_ */
