#include "JsonUtil.h"
#include <windows.h>

#include "TestData.h"

#define ADD_TO_CONTAINER(className, jsonFileName){ \
	if(AddToDataContainerFromJsonFile<className>(currentFolder + jsonScriptFolderPath + jsonFileName) == false) \
	{ \
		return false; \
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

		ADD_TO_CONTAINER(Test1, "Test1.json");
		ADD_TO_CONTAINER(Test2, "Test2.json");

		return true;
	}
}