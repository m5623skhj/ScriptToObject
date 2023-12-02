#pragma once
#include "DataUtil.h"
#include <list>

class Test1 : public DataObjectBase
{
public:
	SET_DATA_OBJECT(Test1, int)

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
	SET_DATA_OBJECT(Test2, std::string_view);

	virtual bool PostLoad()
	{
		return true;
	}

	std::string id;
	float fl;
};