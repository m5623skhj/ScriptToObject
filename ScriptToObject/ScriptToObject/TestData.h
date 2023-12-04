#pragma once
#include "DataObjectBase.h"
#include "DataMacro.h"

class Test1 : public DataObjectBase
{
public:
	int id;
	std::string stringItem;

public:
	SET_DATA_OBJECT(Test1, id);

	virtual void LoadFromJson(const nlohmann::json& jsonObject) override
	{
		id = jsonObject["id"];
		stringItem = jsonObject["stringItem"];
	}

	virtual bool PostLoad()
	{
		return true;
	}
};

class Test2 : public DataObjectBase
{
public:
	std::string id;
	float fl;

public:
	SET_DATA_OBJECT(Test2, id);

	virtual void LoadFromJson(const nlohmann::json& jsonObject) override
	{
		id = jsonObject["id"];
		fl = jsonObject["fl"];
	}

	virtual bool PostLoad()
	{
		return true;
	}

};