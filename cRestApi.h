#pragma once

#include "json.hpp"

class cRestApi
{

public:
	cRestApi() {};

	virtual nlohmann::json GetParsedResponse() const {
		return nlohmann::json();
	};
};

