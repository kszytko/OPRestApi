#pragma once
#include <iostream>

#include "cWebRestApi.h"
#include "cFileRestApi.h"

#include "json.hpp"

#include "cMachine.h"


using namespace nlohmann;

int main() {
	//cWebRestApi restApi;
	//restApi.GetRequest(284);

	cFileRestApi restApi("data.json");

	json jObject = restApi.GetParsedResponse();

	std::vector<cMachine> machines;


	for (auto& el : jObject["_embedded"]["results"]["_embedded"]["elements"])
	{
		std::string workObjectType = el["_links"]["type"]["title"].get<std::string>();

		cMachine machine;
		auto& links = ;


		
		
		if (workObjectType == "Machine") {
			machine.type = workObjectType;
			machine.opid = el["id"].get<size_t>();
			machine.description = el["description"]["raw"].get<std::string>();
			machine.loginName = el["customField11"].get<std::string>();
			machine.wanIp = el["customField13"].get<std::string>();
			machine.lanIp = el["customField12"].get<std::string>();
			machine.teamViewerId = el["customField14"].get<size_t>();
			machine.id = el["customField15"].get<size_t>();

			//Links
			machine.projectName = links["project"]["title"].get<std::string>();// "=PLC32_FR02"
			machine.status = links["status"]["title"].get<std::string>();// "New"

			//only machinetask should have parent
			if (!links["parent"]["title"].is_null()) {
				machine.parentName = links["parent"]["title"].get<std::string>();// "ZSHWRW001635"
				machine.parentID = links["parent"]["href"].get<std::string>();// "/api/v3/work_packages/957",
			}
			else {
				machine.parentName = "None";
				machine.parentID = "None";
			}

			machines.push_back(machine);

		}

		if (workObjectType == "MachineTask") {
			machine.type = workObjectType;
			machine.opid = el["id"].get<size_t>();
			machine.description = el["description"]["raw"].get<std::string>();
			machine.loginName = el["customField11"].get<std::string>();
			machine.wanIp = el["customField13"].get<std::string>();
			machine.lanIp = el["customField12"].get<std::string>();
			machine.teamViewerId = el["customField14"].get<size_t>();
			machine.id = el["customField15"].get<size_t>();

			//Links
			machine.projectName = links["project"]["title"].get<std::string>();// "=PLC32_FR02"
			machine.status = links["status"]["title"].get<std::string>();// "New"

			//only machinetask should have parent
			if (!links["parent"]["title"].is_null()) {
				machine.parentName = links["parent"]["title"].get<std::string>();// "ZSHWRW001635"
				machine.parentID = links["parent"]["href"].get<std::string>();// "/api/v3/work_packages/957",
			}
			else {
				machine.parentName = "None";
				machine.parentID = "None";
			}

			machines.push_back(machine);
		}


		//Element
		

	}

	for (auto& machine : machines) {
		std::cout << machine.id << "\n"
			<< machine.opid << "\n"
			<< machine.machineName << "\n"
			<< machine.description << "\n"
			<< machine.loginName << "\n"
			<< machine.wanIp << "\n"
			<< machine.lanIp << "\n"
			<< machine.teamViewerId << "\n"

			<< machine.type << "\n"
			<< machine.projectName << "\n"
			<< machine.parentID << "\n"
			<< machine.parentName << "\n"
			<< machine.status << "\n"
		<< "\n\n";
	}

}