#include <iostream>
#include "test.h"
#include "gtest/gtest.h"
#include "pch.h"
//#include "test.h"



int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}