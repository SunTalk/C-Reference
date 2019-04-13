#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("q1.data","r",stdin);
	freopen("p1.out","w",stdout);

	string str,check;
	int table[4];

	while( cin >> str >> check ){
		
		transform(str.begin(),str.end(),str.begin(),::toupper);
		transform(check.begin(),check.end(),check.begin(),::toupper);
		
		memset(table,0,sizeof(table));
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] == 'A' )
				table[0]++;
			if( str[i] == 'C' )
				table[1]++;
			if( str[i] == 'G' )
				table[2]++;
			if( str[i] == 'T' )
				table[3]++;
		}

		printf("%d %d %d %d\n",table[0],table[1],table[2],table[3] );

		vector<int > find_ch;
		string tmp;
		for(int i = 0 ; i <= str.size()-check.size() ; i++ ){
			tmp = str.substr(i,check.size());
			if( tmp == check )
				find_ch.push_back(i);
		}

		for(int i = 0 ; i < find_ch.size() ; i++ )
			printf("%d ",find_ch[i]);
		printf("%d\n",find_ch.size());

	}


	return 0;
}