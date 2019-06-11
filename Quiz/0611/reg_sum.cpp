#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string str;

	regex NUM("([+-]?((0[0-7]+)|([1-9][0-9]*)|(0[xX][0-9a-fA-F]+))[lLuUiI]?\\b)");
	smatch find_num;
	vector <string> ans;
	vector <int> ANS;
	bool flag = false;

	while( getline(cin,str) ){

		ans.clear();
		ANS.clear();
		while( regex_search(str,find_num,NUM) ){
			ans.push_back(find_num[0]);
			str = find_num.suffix().str();
		}



		for(int k = 0 ; k < ans.size() ; k++ ){
			transform(ans[k].begin(), ans[k].end(),ans[k].begin(),::toupper);
			
			int i = 0,j = 0;
			int sign = 1;
			int num = 0;
			if( ans[k][i] == '-' )
				sign = 0;
			if( ans[k][i] == '+' || ans[k][i] == '-' )
				i++;

			if( sign == 0 && ans[k][ans[k].size()-1] == 'U' ){
				continue;
			}

			if( ans[k][i] == '0' ){
				if( ans[k][i+1] == 'x' || ans[k][i+1] == 'X' ){

					num = 0;
					for( j = i+2 ; j < ans[k].size() ; j++ ){
						if( ans[k][j] == 'U' || ans[k][j] == 'L' || ans[k][j] == 'I' )
							break;
						num = num*16;
						if( ans[k][j] >= '0' && ans[k][j] <= '9' )
							num = num + (ans[k][j]-'0');
						else
							num = num + (ans[k][j]-'A'+10);
					}

					if( sign == 0 )
						num = num*(-1);

					ANS.push_back(num);

				}
				else{

					num = 0;
					for( j = i+1 ; j < ans[k].size() ; j++ ){
						if( ans[k][j] == 'U' || ans[k][j] == 'L' || ans[k][j] == 'I' )
							break;
						num = num*8;
						num = num + (ans[k][j]-'0');
					}

					if( sign == 0 )
						num = num*(-1);

					ANS.push_back(num);
				}
			}
			else{
				num = 0;
				for(int j = i ; j < ans[k].size() ; j++ ){
					if( ans[k][j] == 'U' || ans[k][j] == 'L' || ans[k][j] == 'I' )
						break;
					num = num*10;
					num = num + (ans[k][j]-'0');
				}

				if( sign == 0 )
					num = num*(-1);

				ANS.push_back(num);
			}
			
		}

		sort(ANS.begin(), ANS.end(),greater<int>());

		if( flag )
			printf("\n");
		flag = true;

		int tmp = ANS[0];
		printf("%d",ANS[0] );
		for(int i = 1 ; i < ANS.size() ; i++ ){
			tmp += ANS[i];
			printf(" %d",ANS[i] );
		}
		printf("\n%d\n",tmp);

	}

	return 0;
}