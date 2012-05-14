/*
 * testUnit.h
 *
 *  Created on: May 3, 2012
 *      Author: jyagati
 */

#ifndef TESTUNIT_H_
#define TESTUNIT_H_

#include "Dbconnect.h"

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <netinet/in.h>
using namespace std;
using namespace CppUnit;

class testUnit:public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(testUnit);
	CPPUNIT_TEST(DbcheckConnection);
	//CPPUNIT_TEST(DBUpdate);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:

	void DbcheckConnection();
	//void DBUpdate();

private:
	MYSQL* mt_pConnection;
	char* mt_pUserName;
	char* mt_pPwd;
	char* mt_pDbName;
	char* mt_pHostname;
	char* mt_query;

	Dbconnect* mDbObj;
};

#endif /* TESTUNIT_H_ */
