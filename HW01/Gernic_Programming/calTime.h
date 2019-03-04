#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<iomanip>

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

void Print_Time( vector<string> &list_title , vector<float> &time_list ){

	freopen("TimeList.out","a",stdout);

	string tmp;
	for(int i = 0 ; i < time_list.size() ; i++ ){
		tmp = list_title[i];
		while( tmp.size() < 10 )
			tmp = tmp + " ";
		cout << tmp << "    " << time_list[i] << endl ;
	}
	cout << endl;
}