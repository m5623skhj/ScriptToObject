#include "JsonUtil.h"
#include <windows.h>
#include "DataUtil.h"

#include "TestData.h"

#define ADD_TO_CONTAINER(className, jsonFileName){ \
	std::cout << "Start loading : " << jsonFileName << std::endl; \
	if(AddToDataContainerFromJsonFile<className>(currentFolder + jsonScriptFolderPath + jsonFileName) == false) \
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
		std::string currentFolder = GetCurrentFolder();

		std::cout << std::endl
			<< "--------------------------------------" << std::endl
			<< "Start load from " << currentFolder << std::endl
			<< "--------------------------------------" << std::endl;

		ADD_TO_CONTAINER(Test1, "Test1.json");
		ADD_TO_CONTAINER(Test2, "Test2.json");

		std::cout << std::endl
			<< "--------------------------------------" << std::endl
			<< "All files loaded successfully" << std::endl
			<< "Start PostLoad()"  << std::endl
			<< "--------------------------------------" << std::endl;

		POST_LOAD(Test1);
		POST_LOAD(Test2);

		std::cout << std::endl
			<< "--------------------------------------" << std::endl
			<< "PostLoad() successfully" << std::endl
			<< "--------------------------------------" << std::endl;

		return true;
	}
}