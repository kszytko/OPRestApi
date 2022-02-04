#pragma once
#include "cRestApi.h"
#include <fstream>


class cFileRestApi : public cRestApi
{
public:
	cFileRestApi(std::string _filename) : filename(_filename) {
	};

private:
	std::string filename;
	std::ifstream ifs;


public:
	bool GetRequest()  override;
	nlohmann::json GetParsedResponse() const;

};