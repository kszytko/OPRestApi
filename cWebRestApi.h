#pragma once
#include "restclient-cpp/restclient.h"
#include "restclient-cpp/connection.h"
#include "cRestApi.h"

class cWebRestApi : public cRestApi
{

public:
	cWebRestApi() {};
	cWebRestApi(std::string _serverAdr, std::string _apikey) : serverAdr(_serverAdr), apikey(_apikey) {};

private:
	std::string apikey = "a5f282d80dae33474066633bd5f16cb4fca06efbc19c87dc40f32284e46a6c18";
	std::string serverAdr = "http://10.137.24.110/api/v3";

	RestClient::Response r;
	bool validResponse;
	
public:
	bool GetRequest(size_t querryID);
	virtual nlohmann::json GetParsedResponse() const;

};

