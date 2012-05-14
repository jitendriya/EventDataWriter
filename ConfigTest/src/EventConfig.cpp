/*
 * EventConfig.cpp
 *
 *  Created on: May 9, 2012
 *      Author: jitendriya
 */

#include "EventConfig.h"

EventConfig::EventConfig() {

	// TODO Auto-generated constructor stub

}

EventConfig::~EventConfig() {
	// TODO Auto-generated destructor stub
}

int EventConfig::read()
	{
	//EvenDataConfig config;
	vector <string> file;
	char *key_string;
	char *value;
	char *saveptr1;


	  string textLine;

	      // try to open a file

	      ifstream ifs("Config.conf",ifstream::in);

	     // if (ifs.good())  { // if opening is successful

	            // while file has lines


	    	while(!ifs.eof()){

	    		getline(ifs,textLine);
	    			file.push_back(textLine);
	                  // read line of text



	           }

				  value = new char[file[0].size()];
				   value = strdup(file[0].c_str());
				   key_string = strtok_r(value,"=",&saveptr1);

				   string confile[9];
				   int tokencount = 0;
				   while(key_string != NULL)
				   {
					   confile[tokencount] = key_string;
						   tokencount++;
						   key_string = strtok_r(NULL,"/",&saveptr1);
				   /*if(key_string == "sleep_delta")
	                  {
	                	 config.sleep_delta = atoi(value);
	                	 cout << config.sleep_delta;


	                  }*/
				   }

	                  cout<<confile[0]<<endl;
	                  cout<<confile[1]<<endl;
	                  cout<<confile[2]<<endl;
	                  cout<<confile[3]<<endl;
	                  cout<<confile[4]<<endl;
	                  cout<<confile[5]<<endl;
	                  cout<<confile[6]<<endl;



	      pause();

	    // close the file


//else
	    	//  cout<<"file not open" <<endl;
	            return 0;

	      }


	            // otherwise print a message

