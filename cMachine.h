#pragma once
#include <string>
struct cMachine
{
	size_t	id;
	size_t	opid;
	std::string machineName;
	std::string description;
	std::string loginName;
	std::string type;
	std::string wanIp;
	std::string lanIp;
	std::string vmPort;
	std::string teamViewerId;
	std::string projectName;
	std::string parentID;
	std::string parentName;
	std::string status;
};

