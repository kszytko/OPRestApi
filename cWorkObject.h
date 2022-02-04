#pragma once
#include <string>

class cWorkObject {

public:

	virtual void print() const = 0;

public:
	size_t	id;
	std::string type;

};
