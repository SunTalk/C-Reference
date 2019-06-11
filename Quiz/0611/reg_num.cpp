#include <bits/stdc++.h>
using namespace std;

bool is_NUM(const string &num_ ){
	// auto pattern = R"(^[+-]*((0[1-7][0-7]{0,})|([1-9][0-9]{0,})|(0[xX][0-9a-f]+))[lui]*$)";
	// regex NUM(pattern, regex_constants::icase);
	regex NUM("(^[+-]*((0[1-7][0-7]{0,})|([1-9][0-9]{0,})|(0[xX][0-9a-fA-F]+))[lLuUiI]*$)");
	return regex_match(num_,NUM);
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string str;
	while( cin >> str ){

		if( is_NUM(str) ){
			transform(str.begin(), str.end(),str.begin(),::toupper);
			// cout << str << " : ";
			bool ans = true;
			int i = 0,j = 0;
			int sign = 1;
			int num = 0;
			if( str[0] == '-' )
				sign = 0;
			if( str[i] == '+' || str[i] == '-' )
				i++;

			if( sign == 0 && str[str.size()-1] == 'U' ){
				cout << "FALSE\n" ;
				break;
			}

			if( str[i] == '0' ){
				if( str[i+1] == 'x' || str[i+1] == 'X' ){

					num = 0;
					for( j = i+2 ; j < str.size() ; j++ ){
						if( str[j] == 'U' || str[j] == 'L' || str[j] == 'I' )
							break;
						num = num*16;
						if( str[j] >= '0' && str[j] <= '9' )
							num = num + (str[j]-'0');
						else
							num = num + (str[j]-'A'+10);
					}

					cout << "TRUE ";
					if(str[j] != 'U')
						cout << (sign ? "+":"-") ;
					cout << num << endl;

				}
				else{

					num = 0;
					for( j = i+1 ; j < str.size() ; j++ ){
						if( str[j] == 'U' || str[j] == 'L' || str[j] == 'I' )
							break;
						if( str[j] >= '8' ){
							cout << "FALSE\n" ;
							break;
						}
						num = num*8;
						num = num + (str[j]-'0');
					}

					cout << "TRUE ";
					if(str[j] != 'U')
						cout << (sign ? "+":"-") ;
					cout << num << endl;
				}
			}
			else
				cout << "TRUE\n";

		}
		else
			cout << "FALSE\n";

	}

	return 0;
}