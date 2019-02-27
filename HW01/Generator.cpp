#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("input.in","r",stdin);
	srand( (unsigned)time(NULL) );
	int N,M;
	int tmp,i,j;
	int test_case = 1;

	string s = "data";

	while( ~scanf("%d %d",&N,&M) ){

		freopen( (s + to_string(test_case)).c_str() , "w" , stdout );
		string ans;
		for( i = 0 ; i < N ; i++ ){
			ans = "";
			for( j = 0 ; j < M ; j++ ){
				tmp = rand() % (126 - 32 + 1) + 32;
				char add = tmp;
				ans = ans + add;
			}
			cout << ans << endl;
		}
		test_case++;

	}

	return 0;
}