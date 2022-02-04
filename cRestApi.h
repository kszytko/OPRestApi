#pragma once

#include "json.hpp"

class cRestApi
{

public:
	virtual bool GetRequest() = 0;
	virtual nlohmann::json GetParsedResponse() const = 0;
};

