#pragma once
#include "cWorkObject.h"
#include <iostream>

class cMachineTask : public cWorkObject {

public:
	void print() const override{
		std::cout << type << "\n"
			<< "  id           : " << id << "\n"
			<< "  taskName     : " << taskName << "\n"
			<< "  description  : " << description << "\n"
			<< "  projectName  : " << projectName << "\n"
			<< "  parentID     : " << parentID << "\n"
			<< "  parentName   : " << parentName << "\n"
			<< "  status       : " << status<< "\n\n";
	}

public:
	std::string taskName;
	std::string description;
	std::string projectName;
	std::string parentID = "none";
	std::string parentName = "none";
	std::string status;
};