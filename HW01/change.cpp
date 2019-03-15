#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("Iterator_intput.txt","r",stdin);

	float num;
	int count = 1;
	vector<float>table[20];
	while( cin >> num ){
		table[1].push_back(num);
		for(int i = 2 ; i < 19 ; i++){
			cin >> num;
			table[i].push_back(num);
		}
	}

	freopen("Iterator_input.txt","w",stdout);
	for(int i = 1 ; i <19 ; i++){
		for(int j = 0 ; j < table[i].size() ; j++)
			printf("%f ",table[i][j] );
		printf("\n");
	}

	return 0;
}