#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{	
	string str,check;
	while( cin >> str >> check ){
		
		transform(str.begin(),str.end(),str.begin(),::toupper);
		transform(check.begin(),check.end(),check.begin(),::toupper);
		printf("%d %d %d %d\n",count(str.begin(), str.end(),'A'),count(str.begin(), str.end(),'C'),count(str.begin(), str.end(),'G'),count(str.begin(), str.end(),'T') );

		int ans = 0;
		int tmp = str.find(check,0);
		while( tmp != string::npos ){
			printf("%d ",tmp );
			tmp = str.find(check,tmp+1);
			ans++;
		}
		printf("%d\n",ans );

	}

	return 0;
}