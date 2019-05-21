#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	regex is_phone("\\+\\(\\d{3}\\)\\-\\d\\-\\d{4}\\-\\d{4}");
	regex encryption("\\+\\(\\d{3}\\)\\-\\d\\-\\d{4}");
	smatch phone;
	string str;

	while( getline(cin,str) ){

		if( regex_search(str,phone,is_phone) ){
			string tmp = phone[0];
			if( tmp[7] == tmp[9] ){
				str = regex_replace(str,encryption,"+(XXX)-X-XXXX$2");
			}
		}

		cout << str << endl;


	}

	return 0;
}