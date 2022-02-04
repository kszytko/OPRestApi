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
	


public:

	nlohmann::json GetParsedResponse() const {
		std::ifstream ifs(filename, std::ios::binary);

		return nlohmann::json::parse(ifs);

	};

};