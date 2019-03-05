#include<iostream>
#include<iomanip>
#include<iterator>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

#define TIME_TEST

#include<rand.h>
#include<calTime.h>

void usage(string str){

	cout << "Usage: " << str << "fileName" << endl;
}

int main(int argc, char const *argv[]){
	freopen("output.out","w",stdout);
	vector<float> time_list;
	vector<string> title_list;

	if(argc != 2){

		usage(argv[0]);
		exit(1);
	}

	string fileName = argv[1];
	int length = fileName.size();
	char arr[length+1];
	strcpy(arr, fileName.c_str());

	freopen(arr, "r", stdin);

	vector<string> v;
	string tmp;

	T_START();
	while(getline(cin, tmp))
		v.push_back(tmp);
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("input");

	T_START();
	sort(v.begin(), v.end());
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("sort");

	T_START();
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n") );
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("output");

	Print_Time(fileName,title_list,time_list);

	return 0;
}

