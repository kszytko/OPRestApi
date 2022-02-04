#include "cFileRestApi.h"

bool cFileRestApi::GetRequest(){
	return true;
};

nlohmann::json cFileRestApi::GetParsedResponse() const {
	std::ifstream iff(filename, std::ios::binary);

	return nlohmann::json::parse(iff);

};