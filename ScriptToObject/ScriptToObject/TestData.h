#pragma once
#include "DataObjectBase.h"
#include "DataMacro.h"

class Test1 : public DataObjectBase
{
public:
	SET_DATA_OBJECT(Test1, int, id);

	virtual void LoadFromJson(const nlohmann::json& jsonObject) override
	{
		id = jsonObject["id"];
		stringItem = jsonObject["stringItem"];
	}

	virtual bool PostLoad()
	{
		return true;
	}

	int id;
	std::string stringItem;
};

class Test2 : public DataObjectBase
{
public:
	SET_DATA_OBJECT(Test2, std::string_view, id);

	virtual void LoadFromJson(const nlohmann::json& jsonObject) override
	{
		id = jsonObject["id"];
		fl = jsonObject["fl"];
	}

	virtual bool PostLoad()
	{
		return true;
	}

	std::string id;
	float fl;
};