#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("g2.data","w",stdout);
	string tmp;

	tmp = argv[1];
	int times = 0;
	for(int i = 0 ; i < tmp.size() ; i++ )
		times = times*10 + tmp[i]-'0';
	tmp = argv[2];
	int len = 0;
	for(int i = 0 ; i < tmp.size() ; i++ )
		len = len*10 + tmp[i]-'0';

	srand( time(NULL) );
	
	printf("%d %d\n",times,len );
	for(int i = 0 ; i < times*len ; i++ )
		printf("%d",rand()%10 );

	return 0;
}