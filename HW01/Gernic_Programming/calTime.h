#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<iomanip>

#ifdef TIME_TEST
	
	#define T_OUT() \
	do { \
		\
		std::ofstream out("result.txt", ios_base::out|ios_base::app);\
		out << std::fixed << std::setprecision(5) << T_CAL_SEC() << endl;\
	}while(0)

	#define PUTCHAR() \
	do{\
		\
		std::ofstream out("result.txt", ios_base::out|ios_base::app); \
		out << endl; \
	}while(0)

#endif

static clock_t startTime; 

void T_START(){

	startTime = clock();
}

void T_END(){

	startTime = clock() - startTime;
}

int T_GET_START_TIME(){

	return startTime;
}

float T_CAL_SEC(){

	return (float)startTime / CLOCKS_PER_SEC;

}

void Print_Time(string file_name, vector<string> &list_title , vector<float> &time_list ){

	freopen("TimeList_ver3.list","a",stdout);

	string tmp;
	float total = 0;
	
	cout << file_name << endl;
	for(int i = 0 ; i < time_list.size() ; i++ ){
		tmp = list_title[i];
		while( tmp.size() < 10 )
			tmp = tmp + " ";
		cout << tmp << "    " << time_list[i] << endl ;
		total = total + time_list[i];
	}
	cout << "total         " << total << endl;
	cout << endl;
}

