#include <bits/stdc++.h>
using namespace std;

bool is_TIME(const string &ip ){
	auto pattern = R"(^([0-9]{2}:){2}[0-9]{2}$)";
	regex TIME(pattern);
	return regex_match(ip,TIME);
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string str;
	int hour,min,sec;
	while( cin >> str ){
		
		bool ans = false;
		if( is_TIME(str) ){
			hour = min = sec = 0;
			hour = 10*(str[0]-'0')+(str[1]-'0');
			min = 10*(str[3]-'0')+(str[4]-'0');
			sec = 10*(str[6]-'0')+(str[7]-'0');

			if( hour <= 23 && min <= 59 && sec <= 59 )
				ans = true;

		}

		cout << ( ans ? "TRUE\n" : "FALSE\n" );

	}

	return 0;
}