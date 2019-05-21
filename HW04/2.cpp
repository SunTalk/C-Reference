#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	regex card("^\\d{4}\\-\\d{4}\\-\\d{4}\\-\\d{4}$");
	smatch find_word;

	string str;
	int ans,tmp;

	while( cin >> str ){


		if( regex_match(str,card) ){
			ans = 0;
			tmp = 1000;
			for(int i = 0 ; i < str.size() ; i++ ){
				if( str[i] == '-' )
					tmp = 10000;
				else
					ans = ans + (str[i]-'0')*tmp;
				tmp /= 10;
			}
			printf("True %d\n",ans);
		}
		else
			printf("False\n");

		printf("\n");

	}

	return 0;
}