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

clock_t T_END(){

	return clock() - startTime;
}


int T_GET_START_TIME(){

	return startTime;
}

float T_CAL_SEC(){

	return (float)startTime / CLOCKS_PER_SEC;
}
