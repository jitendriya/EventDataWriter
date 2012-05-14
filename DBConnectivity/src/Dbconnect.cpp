/*
 * Dbconnect.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: jyagati
 */

#include "../inc/Dbconnect.h"

#include <mysql/mysql.h>
#include <string>




Dbconnect::Dbconnect() {

	append = true;
	mode = 00664;
	fsize = 100;

	time_t now = time(0);

	// Convert now to tm struct for local timezone
	tm* localtm = localtime(&now);
	cout << "The local date and time is: " << asctime(localtm) << endl;

	char charArrFileName[128]={};
	sprintf(charArrFileName, "./mylogtest-%d-%d-%d.log", localtm->tm_year+1900, localtm->tm_mon+1, localtm->tm_mday);

	string strFileName(charArrFileName);

	//appender = new log4cpp :: FileAppender("FileAppender",LOGDIR);
	appender= new log4cpp::FileAppender("DailyRollingFileAppender",strFileName);
	//app1=new log4cpp::RollingFileAppender("RollingFileAppender",LOGDIR,fsize,1,append,00664);

	/*appender->setMaxBackupIndex(1);
	appender->setMaximumFileSize(1024);*/

	layout = new log4cpp::PatternLayout();

	std::string fpattern ="%d{%d.%m.%Y}";
	layout->setConversionPattern(fpattern);
	//appender = new log4cpp::FileFileAppender("RollingFileAppender",LOGDIR,append,00664);
	std::string pattern = "%d{%d.%m.%Y %H:%M:%S(%lms)} --- %p: %x %m %n";
	layout->setConversionPattern(pattern);


//	log4cpp::Category& category=log4cpp::Category::getInstance("Category");




	/*	m_pUserName = "root";
		m_pPwd = "jyagati";
		m_pDbName = "mysql";
		m_pHostname ="localhost";
		//m_pDbQuery = "select *from emp22"; */
	// TODO Auto-generated constructor stub

}

Dbconnect::~Dbconnect() {

	mysql_free_result(m_pResult);
	mysql_close(m_pConnection);
	category.debug("shutting down");
	log4cpp::Category::shutdown();
	// TODO Auto-generated destructor stub
}
int Dbconnect :: setDbdetails(char* UserName,char* Pwd,char* DbName,char *Hostname)
{
	//log4cpp::Category& category = log4cpp::Category::getInstance("Category");
	category.setAdditivity(false);
	//category.addAppender(appender);
	m_pUserName = UserName;
	m_pPwd = Pwd;
	m_pDbName = DbName;
	m_pHostname = Hostname ;


	return 0;

}

int Dbconnect ::CheckConnect()
{
	appender->setLayout(layout);
	//app1->setLayout(layout);
	category.setAppender(appender);

	category.setPriority(log4cpp::Priority::NOTSET);
	category.info("Checking Dbconnection");
	m_pConnection = mysql_init(NULL);

	if(!mysql_real_connect(m_pConnection,m_pHostname,m_pUserName,m_pPwd,m_pDbName,0,NULL,0))
	{
	// cout <<" Database Connection Error" <<mysql_error(m_pConnection);
	 category.log(log4cpp::Priority::ERROR,"This will be logged errors");

	}



	/*if(mysql_query(m_pConnection,m_pDbQuery))
	{
		cout << "Query execution Error" << mysql_error(m_pConnection);
	}
	m_pResult = mysql_use_result(m_pConnection);

	cout << "\n Employee Values" <<endl;
				while((m_pRow = mysql_fetch_row(m_pResult)) != NULL)
					cout<< "ename \t" <<m_pRow[0] << "\t eno\t" <<m_pRow[1] <<endl; */

	return 0;

}
int Dbconnect ::exeQuery(char* query)
{
	m_pDbQuery = query;
		if(mysql_query (m_pConnection ,m_pDbQuery))
		{
			//cout << "Query syntax error " << mysql_error(m_pConnection) << endl;
			category.log(log4cpp::Priority::ERROR,"Query Syntax Error");
		}
		else
		{

			category.alert("alert for execution");

			m_pResult = mysql_store_result(m_pConnection) ;
			//m_pRow = mysql_fetch_row(m_pResult);
		}

	return 0;
}

int Dbconnect ::DbFetch()
{
	//m_pResult =  mysql_store_result(m_pConnection);
	//cout << "\n \t  Employee Values \t\t" << endl;
//	cout << "\n ename" << "\t\t " <<"eno" <<endl;
			category.debug("Debugging the Db Table");
			while( NULL != (m_pRow = mysql_fetch_row(m_pResult)) )
			{

			cout <<m_pRow[0]<< "\t \t" << m_pRow[1] <<endl;


		}
	return 0;
}

int Dbconnect:: DbUpdate(char *pQuery)
{
	m_pDbQuery = pQuery;
   unsigned long m_pAfRow;
	   category.info(" UPDATE");
	if(mysql_query(m_pConnection,m_pDbQuery))
	{
		//cout << mysql_error(m_pConnection) <<endl;
		category.log(log4cpp::Priority::NOTICE,"Table not updated");
	}
	else
	{

		m_pResult = mysql_store_result(m_pConnection) ;
		cout << "\n Database Updated" <<endl;
		m_pAfRow =mysql_affected_rows(m_pConnection);
		cout <<"affected rows \t" <<m_pAfRow <<endl;
	}
	return 0;
}

