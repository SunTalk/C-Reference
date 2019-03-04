#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
#include<fstream>
#include<cstdlib>

void init_randseed(){

	srand(time(NULL));
}

int rand_Ascii(int left, int right){

	return left + (rand() % (right - left) + 1);
}

std::string rand_string(int len){

	std::string tmp;
	for(int i = 0 ; i < len ; i++)
		tmp += char(rand_Ascii(32, 126));

	return tmp;
}

void gen_to_file(std::string fileName, int size, int len){

	std::ofstream fout(fileName);
	for(int i = 0 ; i < size ; i++)
		fout << rand_string(len) << std::endl;
}