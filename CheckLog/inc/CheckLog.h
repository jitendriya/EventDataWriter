/*
 * CheckLog.h
 *
 *  Created on: May 9, 2012
 *      Author: jitendriya
 */

#ifndef CHECKLOG_H_
#define CHECKLOG_H_
#include <fstream>
#include <iostream>

class CheckLog
{
public:
	CheckLog();
	~CheckLog();
	int checkFile();
private:
	FILE *fd;
};
#endif /* CHECKLOG_H_ */
