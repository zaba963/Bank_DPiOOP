// Bank_DPiOOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

#include "DataBase.h"

using namespace std;

int main()
{
	srand(time(NULL));


	DataBase::get().addData(new DataBase::_data("haslo", 0, "aaa", "bbb", 0, DataBase::ADMIN));





	system("pause");
    return 0;
}

