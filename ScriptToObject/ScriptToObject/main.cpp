#include <iostream>
#include "TestData.h"
#include "DataUtil.h"

int main()
{
	auto t1 = MAKE_DATA_OBJECT(Test1);
	auto t11 = MAKE_DATA_OBJECT(Test1);
	auto t2 = MAKE_DATA_OBJECT(Test2);
	auto t22 = MAKE_DATA_OBJECT(Test2);

	t1->id = 1;
	t1->stringItem = "1111";
	t11->id = 2;
	t11->stringItem = "2222";

	t2->fl = 1.111f;
	t2->id = "1";
	t22->fl = 2.222f;
	t22->id = "2";

	ADD_DATA(Test1, t1->id, t1);
	ADD_DATA(Test1, t11->id, t11);
	ADD_DATA(Test2, t2->id, t2);
	ADD_DATA(Test2, t22->id, t22);

	auto temp1 = FIND_DATA(Test1, 1);
	auto tempErr = FIND_DATA(Test1, 100);

	auto temp2 = FIND_DATA(Test2, "2");

	return 0;
}
