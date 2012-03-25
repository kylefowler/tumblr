/*
 * ApiResponse.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef APIRESPONSE_H_
#define APIRESPONSE_H_

#include "ApiResponseObjectFactory.h"
#include "ResponseMeta.h"

class ApiResponse {
public:
	ApiResponse(ApiResponseObjectFactory::ApiType);
	virtual ~ApiResponse();
	void parse(QByteArray);
	AbstractObjectBase* getResponse();
	ResponseMeta* getMeta();
private:
	ResponseMeta* meta;
	AbstractObjectBase* response;
};

#endif /* APIRESPONSE_H_ */
