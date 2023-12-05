#include "JsonUtil.h"
#include <windows.h>
#include "DataUtil.h"
#include "Config.h"

#include "TestData.h"

#define ADD_TO_CONTAINER(className, jsonFileName){ \
	std::cout << "Start loading : " << jsonFileName << std::endl; \
	if(AddToDataContainerFromJsonFile<className>(currentFolder + Configuration::Config::GetInst().jsonScriptFolderPath + jsonFileName) == false) \
	{ \
		std::cout << "Load failed : " << jsonFileName << std::endl; \
		return false; \
	} \
	std::cout << "Load completed : " << jsonFileName << std::endl; \
}

#define POST_LOAD(className){ \
	if(DataContainer<className::DataKeyType, className>::GetInst().PostLoad() == false) \
	{ \
		std::cout << "PostLoad() failed : " << #className << std::endl; \
	} \
}

namespace JsonUtil
{
	std::string GetCurrentFolder()
	{
		char buffer[MAX_PATH];
		GetCurrentDirectoryA(MAX_PATH, buffer);
		return std::string(buffer);
	}

	bool LoadAllDataScript()
	{
		if (Configuration::LoadConfiguration(Configuration::configurationFilePath) == false)
		{
			return false;
		}

		std::string currentFolder = GetCurrentFolder();

		std::cout << std::endl
			<< "--------------------------------------" << std::endl
			<< "Start load from " << currentFolder << std::endl
			<< "--------------------------------------" << std::endl;

#pragma region AddToContainer

		ADD_TO_CONTAINER(Test1, "Test1.json");
		ADD_TO_CONTAINER(Test2, "Test2.json");

#pragma endregion AddToContainer

		std::cout << std::endl
			<< "--------------------------------------" << std::endl
			<< "All files loaded successfully" << std::endl
			<< "Start PostLoad()"  << std::endl
			<< "--------------------------------------" << std::endl;

#pragma region PostLoad

		POST_LOAD(Test1);
		POST_LOAD(Test2);

#pragma endregion PostLoad

		std::cout << std::endl
			<< "--------------------------------------" << std::endl
			<< "PostLoad() successfully" << std::endl
			<< "--------------------------------------" << std::endl;

		return true;
	}
}