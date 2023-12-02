#pragma once

#include "TestData.h"

#pragma region DataRegister

#define DATA_REGISTER(){ \
	ADD_DATA_CLASS_TO_GENERATOR(Test1); \
	ADD_DATA_CLASS_TO_GENERATOR(Test2); \
}

#pragma endregion DataRegister