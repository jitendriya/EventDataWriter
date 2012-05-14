//============================================================================
// Name        : CheckLog.cpp
// Author      : jitendriya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


#include "CheckLog.h"

CheckLog::CheckLog() {
	//fd = fopen("/home/jitendriya/EventDataWriter/DBConnectivity/mylogtest-2012-5-8.log","r");
	// TODO Auto-generated constructor stub

}

CheckLog::~CheckLog() {
	// TODO Auto-generated destructor stub
}

int CheckLog::checkFile()
{

fd=fopen("../DBConnectivity/mylogtest-2012-5-8.log","r");

if(fd)
{
	cout<<"file exists"<<endl;
}
return 0;
}
