#pragma once
#include <iostream>

#include "cWebRestApi.h"
#include "cFileRestApi.h"

#include "json.hpp"

#include "cMachine.h"
#include "cMachineTask.h"
#include "cWorkObject.h"

#include <memory>

#include "AuthData.h"

using namespace nlohmann;

int main() {
	json jObject;

	cWebRestApi restApi(AUTH::SERVER_ADRESS, AUTH::APIKEY, AUTH::QUERRY_ID);
	//cFileRestApi restApi("data.json");

	if(restApi.GetRequest())
	{
		jObject = restApi.GetParsedResponse();
	}
	

	std::vector<std::shared_ptr<cWorkObject>> workobjects;


	for (auto& el : jObject["_embedded"]["results"]["_embedded"]["elements"])
	{
		std::string workObjectType = el["_links"]["type"]["title"].get<std::string>();

		if (workObjectType == "Machine") {
			cMachine machine;

			machine.id = el["id"].get<size_t>();
			machine.type = workObjectType;
			machine.machineName = el["subject"].get<std::string>();
			machine.projectName = el["_links"]["project"]["title"].get<std::string>();// "=PLC32_FR02"
			machine.status = el["_links"]["status"]["title"].get<std::string>();// "New"


			//check if these elements are not null
			if (!el["customField11"].is_null()) 
				machine.loginName = el["customField11"].get<std::string>();
			if(!el["customField12"].is_null())
				machine.lanIp = el["customField12"].get<std::string>();
			if(!el["customField13"].is_null())
				machine.wanIp = el["customField13"].get<std::string>();
			if(!el["customField14"].is_null())
				machine.teamViewerId = el["customField14"].get<size_t>();
			if(!el["customField15"].is_null())
				machine.number = el["customField15"].get<size_t>();

			if (!el["description"]["raw"].is_null())
				machine.description = el["description"]["raw"].get<std::string>();

			workobjects.push_back(std::make_shared<cMachine>(machine));

		}

		if (workObjectType == "MachineTask") {
			cMachineTask task;

			task.id = el["id"].get<size_t>();
			task.type = workObjectType;
			task.taskName = el["subject"].get<std::string>();
			task.projectName = el["_links"]["project"]["title"].get<std::string>();// "=PLC32_FR02"
			task.status = el["_links"]["status"]["title"].get<std::string>();// "New"

			//only machinetask should have parent
			if (!el["_links"]["parent"]["title"].is_null()) {
				task.parentName = el["_links"]["parent"]["title"].get<std::string>();// "ZSHWRW001635"
				task.parentID = el["_links"]["parent"]["href"].get<std::string>();// "/api/v3/work_packages/957",
			}

			if (!el["description"]["raw"].is_null()) 
				task.description = el["description"]["raw"].get<std::string>();


			workobjects.push_back(std::make_shared<cMachineTask>(task));
		}


		//Element
		

	}

	for (auto& wobj : workobjects) {
		wobj->print();
	}

}