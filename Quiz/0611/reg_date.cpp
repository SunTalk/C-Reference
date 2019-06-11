#include <bits/stdc++.h>
using namespace std;

bool is_DATE(const string &date ){
	auto pattern = R"(^[0-9]{2}/[0-9]{2}/[0-9]{4}$)";
	regex DATE(pattern);
	return regex_match(date,DATE);
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string str;
	int big[7] = {1,3,5,7,8,10,12};
	int year,month,day;

	while( cin >> str ){

		bool ans = false;
		if( is_DATE(str) ){
			year = month = day = 0;
			month = 10*(str[0]-'0')+(str[1]-'0');
			day = 10*(str[3]-'0')+(str[4]-'0');
			year = 10*(str[6]-'0')+10*(str[7]-'0')+10*(str[8]-'0')+(str[9]-'0');

			if( month == 2 ){
				if( year%400 == 0 || ( year%4 ==0 && year%100 != 0 ) )
					if( day <= 29 )
						ans = true;
				if( day <= 28 )
					ans = true;
			}
			else if( month <= 12 ){
				for(int i = 0 ; i < 7 ; i++ )
					if( month == big[i] )
						if( day <= 31 )
							ans = true;
				if( day <= 30 )
					ans = true;
			}

		}

		cout << ( ans ? "TRUE\n" : "FALSE\n") ;

	}

	return 0;
}