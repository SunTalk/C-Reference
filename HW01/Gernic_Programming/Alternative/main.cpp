#include<iostream>
#include<iomanip>
#include<iterator>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<ctime>
#include<cstdio>
#include<cstring>

using namespace std;

#define TIME_TEST

#include<rand.h>
#include<calTime.h>

struct  strtab_cmp
{
	typedef  vector<char>::iterator  strtab_iterator;

	bool  operator()( const pair<strtab_iterator, strtab_iterator>& x,
					   const pair<strtab_iterator, strtab_iterator>& y ) const {
		return lexicographical_compare( x.first, x.second, y.first, y.second );
	}
};

struct  strtab_print
{
	typedef  vector<char>::iterator strtab_iterator;
	ostream& out;

	strtab_print(ostream&  os) : out (os) {}

	void  operator()( const pair<strtab_iterator, strtab_iterator>&  s ) const {
		copy( s.first, s.second, ostream_iterator<char>(cout) );
	}
};

void usage(string str){

	cout << "Usage: " << str << " filename" << endl;
}

int main(int argc, char const *argv[])
{	

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

	vector<char>  strtab;	   // Create string table
	char  c;

	T_START();
	while (cin.get(c)) {
		strtab.push_back(c);
	}
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("input");

	cout << T_CAL_SEC() << endl;

	// Parse the string table into lines.
	typedef  vector<char>::iterator  strtab_iterator;
	vector<pair<strtab_iterator, strtab_iterator>> lines;
	strtab_iterator  start = strtab.begin();

	T_START();
	while (start != strtab.end()) {
		strtab_iterator  next = find( start, strtab.end(), '\n' );

		if (next != strtab.end())
			++next;
		lines.push_back( make_pair( start, next ) );
		start = next;
	}
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("CharTable");

	T_START();
	// Sort the vector of lines
	sort( lines.begin(), lines.end(), strtab_cmp() );
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("sort");

	cout << T_CAL_SEC() << endl;

	// Write the lines to standard output
	T_START();
	for_each( lines.begin(), lines.end(), strtab_print(cout) );
	T_END();
	time_list.push_back(T_CAL_SEC());
	title_list.push_back("output");

	cout << T_CAL_SEC() << endl;
	Print_Time(fileName,title_list,time_list);

	return 0;
}
