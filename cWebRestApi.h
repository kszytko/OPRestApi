#pragma once
#include "restclient-cpp/restclient.h"
#include "restclient-cpp/connection.h"
#include "cRestApi.h"

class cWebRestApi : public cRestApi
{

public:
	cWebRestApi() {};
	cWebRestApi(std::string _serverAdr, std::string _apikey, size_t _querryID) : serverAdr(_serverAdr), apikey(_apikey), querryID(_querryID) {};

private:
	std::string apikey;
	std::string serverAdr = "http://localhost/api/v3";
	size_t querryID = 0;

	RestClient::Response r;
	bool validResponse;
	
public:
	bool GetRequest();
	virtual nlohmann::json GetParsedResponse() const;

};

