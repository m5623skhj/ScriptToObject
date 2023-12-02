#pragma once
#include <string>

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
