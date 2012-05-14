/*
 * Dbconnect.h
 *
 *  Created on: Apr 28, 2012
 *      Author: jyagati
 */

#ifndef DBCONNECT_H_
#define DBCONNECT_H_

#include <mysql/mysql.h>


//#include <mysql/my_global.h>
#include <iostream>
#include <stdlib.h>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/SimpleLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/NDC.hh>

#include <ctime>
#define LOGDIR "/home/jitendriya/Log/TestDb"

static log4cpp::Category& category = log4cpp::Category::getInstance("Category");

using namespace std;
using namespace log4cpp;



class Dbconnect {
public:
	Dbconnect();

	int CheckConnect();
	int DbUpdate(char *query);
	int exeQuery(char *query);

	int setDbdetails(char*, char* ,char *,char *);
	int DbFetch();
	virtual ~Dbconnect();

private:
	MYSQL* m_pConnection;
	MYSQL_RES* m_pResult;
	MYSQL_ROW m_pRow;

	char* m_pUserName;
	char* m_pPwd;
	char* m_pDbName;
	char* m_pHostname;
	char* m_pDbQuery;
	log4cpp::FileAppender *appender;
	log4cpp::PatternLayout *layout;
	log4cpp ::Appender* app1;

	//log4cpp ::Category& category;
	string Testdb;
	size_t fsize;
	bool append;
	mode_t mode;
	char date;
};

#endif /* DBCONNECT_H_ */
