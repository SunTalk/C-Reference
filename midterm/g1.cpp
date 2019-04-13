#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("q1.data","w",stdout);

	srand( time(NULL) );

	string tmp;

	tmp = argv[1];
	int times = 0;
	for(int i = 0 ; i < tmp.size() ; i++ )
		times = times*10 + tmp[i]-'0';
	tmp = argv[2];
	int len = 0;
	for(int i = 0 ; i < tmp.size() ; i++ )
		len = len*10 + tmp[i]-'0';
	tmp = argv[3];
	int flen = 0;
	for(int i = 0 ; i < tmp.size() ; i++ )
		flen = flen*10 + tmp[i]-'0';

	char table[] = {'A','C','G','T','a','c','g','t'};

	while( times-- ){

		for(int i = 0 ; i < len ; i++ )
			printf("%c",table[rand()%8]);
		printf(" ");
		for(int i = 0 ; i < flen ; i++ )
			printf("%c",table[rand()%8]);
		printf("\n");
		
	}

	return 0;
}