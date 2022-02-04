#pragma once
#include "cWorkObject.h"

class cMachine : public cWorkObject
{
public:
	void print() const override{
		std::cout << type << "\n" 
			<< " id           :  " << id << "\n"
			<< " number       :  " << number << "\n"
			<< " machineName  :  " << machineName << "\n"
			<< " description  :  " << description << "\n"
			<< " loginName    :  " << loginName << "\n"
			<< " wanIp        :  " << wanIp << "\n"
			<< " lanIp        :  " << lanIp << "\n"
			<< " teamViewerId :  " << teamViewerId << "\n"
			<< " projectName  :  " << projectName << "\n"
			<< " status       :  " << status << "\n\n";
	}
public:
	size_t	number;
	std::string machineName;
	std::string description;
	std::string loginName;
	std::string wanIp;
	std::string lanIp;
	std::string vmPort;
	size_t teamViewerId;
	std::string projectName;
	std::string status;

};

