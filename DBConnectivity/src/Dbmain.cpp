/*
 * Dbmain.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: jyagati
 */


#include <testUnit.h>
#include "Dbconnect.h"
//#include "conf.h"



CPPUNIT_TEST_SUITE_REGISTRATION(testUnit);

int main()
{
	Dbconnect objDb;
	char pUserName[16] = "root";
	char pPwd[16] = "jyagati";
	char  pDbname[16] = "mysql";
	char pHost[16] = "localhost";
	char pQuery[32] = "select *from employee";
	//char pQuery2[64] = "create table emp (ename VARCHAR(30) ,ENO INT)" ;
	//char pQuery3[100] = "insert into emp (ename,eno) values ('rahim',30)";
	//char pQuery4[60] = "select *from emp";
	char pQuery5[100] = "update employee set eno = 20 where ename = 'robert'";
/*	try
	{
		log4cpp::PropertyConfigurator::configure("conf.h");
	}
	catch(log4cpp::ConfigureFailure e)
	{
		cout<<e.what()<<endl;
	}*/
	objDb.setDbdetails(pUserName,pPwd,pDbname,pHost);
	objDb.CheckConnect();
	objDb.exeQuery(pQuery);
	//objDb.DbFetch();
	objDb.DbUpdate(pQuery5);

	CPPUNIT_NS:: TestResult testResult;
	CPPUNIT_NS::TestResultCollector collectedResult;
	testResult.addListener(&collectedResult);

	CPPUNIT_NS :: TestRunner testRunner;
	testRunner.addTest(CPPUNIT_NS :: TestFactoryRegistry ::getRegistry().makeTest());
	testRunner.run(testResult);

	CPPUNIT_NS :: CompilerOutputter compileroutputter(&collectedResult ,std::cerr);
	compileroutputter.write();



	return collectedResult.wasSuccessful() ? 0:1;

}
