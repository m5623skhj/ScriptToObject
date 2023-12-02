#pragma once
#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include <concepts>
#include <fstream>
#include "nlohmann/json.hpp"

class DataObjectBase
{
public:
	virtual ~DataObjectBase() 
	{
	}

	virtual constexpr std::string_view GetObjectTypeName() = 0;
	virtual bool PostLoad() = 0;

protected:
	std::string objectTypeName = "";
};

using DataObjectConstructor = std::function<DataObjectBase*()>;

template<typename T>
concept DataBased = std::is_base_of<DataObjectBase, T>::value;

class DataObjectGenerator
{
private:
	DataObjectGenerator()
	{
	}

public:
	static DataObjectGenerator& GetInst()
	{
		static DataObjectGenerator instance;
		return instance;
	}
	
	void AddDataClass(std::string_view dataClassName, DataObjectConstructor constructor)
	{
		constructorMap.insert({ dataClassName, constructor });
	}

	template <DataBased T>
	T* MakeDataObject(std::string_view dataClassName)
	{
		const auto& iter = constructorMap.find(dataClassName);
		if (iter == constructorMap.end())
		{
			return nullptr;
		}

		return static_cast<T*>(iter->second());
	}

private:
	std::map<std::string_view, DataObjectConstructor> constructorMap;
};

#define ADD_DATA_CLASS_TO_GENERATOR(className) \
DataObjectGenerator::GetInst().AddDataClass(#className, []() -> DataObjectBase* {return new className;})

#define MAKE_DATA_OBJECT(className) \
DataObjectGenerator::GetInst().MakeDataObject<className>(#className)

template<typename DataKeyType, DataBased DataValueType>
class DataContainer
{
private:
	DataContainer()
	{
	}

public:
	static DataContainer& GetInst()
	{
		static DataContainer instance;
		return instance;
	}

	const DataValueType* FindData(DataKeyType key)
	{
		const auto& data = dataMap.find(key);
		if (data == dataMap.end())
		{
			return nullptr;
		}

		return data->second;
	}

	void AddData(DataKeyType key, DataValueType* value)
	{
		dataMap.insert({ key, value });
	}

private:
	std::unordered_map<DataKeyType, DataValueType*> dataMap;
};

#define SET_DATA_OBJECT(className, keyType) \
SET_DATA_KEY_TYPE(keyType);\
SET_OBJECT_TYPE_NAME(className);

#define SET_DATA_KEY_TYPE(type) using DataKeyType = type
#define SET_OBJECT_TYPE_NAME(className) \
virtual constexpr std::string_view GetObjectTypeName() override{ \
	return className; \
}

#define ADD_DATA(classType, key, value) \
DataContainer<classType::DataKeyType, classType>::GetInst().AddData(key, value);

#define FIND_DATA(classType, key) \
DataContainer<classType::DataKeyType, classType>::GetInst().FindData(key)
