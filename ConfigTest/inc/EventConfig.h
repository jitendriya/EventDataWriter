/*
 * EventConfig.h
 *
 *  Created on: May 9, 2012
 *      Author: jitendriya
 */

#ifndef EVENTCONFIG_H_
#define EVENTCONFIG_H_
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;



typedef struct
{
	int sleep_delta;
	int db_retry;
	char db_user[100];
	char db_pwd[20];
	char log_ext[100];
	char process_dir[100];
	char complete_dir[100];
	int log_mode;
	char admin_email[100];
}EvenDataConfig;

typedef struct{
	bool terminate;
	EvenDataConfig config;
}controlEvenDataConfig;

class EventConfig {
public:
	EventConfig();
	virtual ~EventConfig();
	int read();
};

#endif /* EVENTCONFIG_H_ */
