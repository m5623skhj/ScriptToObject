#pragma once
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <list>
#include <optional>
#include "DataObjectBase.h"
#include "DataMacro.h"

namespace JsonUtil
{
	const std::string jsonScriptFolderPath = "\\..\\Script\\";

	std::string GetCurrentFolder();
	bool LoadAllDataScript();

	template<DataBased T>
	std::optional<std::list<T*>> LoadFromJsonFile(std::string filePath)
	{
		std::ifstream jsonFile(filePath);
		if (jsonFile.is_open() == false)
		{
			std::cout << "Failed to open file. Path : " << filePath << std::endl;
			return std::nullopt;
		}

		nlohmann::json jsonData;
		try
		{
			jsonFile >> jsonData;
		}
		catch (nlohmann::json::parse_error& e)
		{
			std::cout << "Parsing error : " << e.what() << std::endl;
			return std::nullopt;
		}

		std::list<T*> objectList;
		{
			T tempObject;
			for (const auto& json : jsonData)
			{
				T* object = MAKE_DATA_OBJECT(T, tempObject.GetObjectTypeName());
				object->LoadFromJson(json);

				objectList.push_back(object);
			}
		}

		return objectList;
	}

	template<DataBased T>
	bool AddToDataContainerFromJsonFile(std::string filePath)
	{
		auto objectList = LoadFromJsonFile<T>(filePath);
		if (objectList == std::nullopt)
		{
			return false;
		}

		for (auto& object : objectList.value())
		{
			object->AddDataToDataContainer();
		}

		return true;
	}
}