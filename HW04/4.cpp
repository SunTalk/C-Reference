#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	regex is_float("\\d*(\\.|[eE][+-]*)\\d*([eE]{1}[+-]*\\d*|[eE]{0})[flFL]?");
	smatch sm_float;
	string str;

	while( getline(cin,str) ){


		if( regex_match(str,is_float) ){
			printf("TRUE\n");
		}
		else{
			printf("FALSE\n");

			while( regex_search(str,sm_float,is_float) ){
				cout << sm_float[0] << endl;
				str = sm_float.suffix().str();
			}

		}

		printf("\n");

	}

	return 0;
}