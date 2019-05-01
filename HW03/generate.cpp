#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("HW03.in","w",stdout);
	srand( time(NULL) );
	string name[] = {"SunTalk","ICEJJ","Roy","HalloWorld","Chess","Bobo","CashLu","Wei","Ina","Amy","Theo","PYC","Dalun"};
	//13

	string N = argv[1]; 
	int num = 0;
	for(int i = 0 ; i < N.size() ; i++ )
		num = num*10 + N[i]-'0';
	
	printf("%d\n",num );
	int tmp;
	string block;
	char add;
	for(int i = 0 ; i < num ; i++ ){
		cout << name[rand()%13] << " ";
		tmp = rand()%100 + 30;
		block = "";
		for(int j = 0 ; j < tmp ; j++ ){
			add = (rand()%26+'A');
			block = block + add;
		}
		cout << block << endl;
	}

	tmp = rand()%3 + 1;
	block = "";
	for(int j = 0 ; j < tmp ; j++ ){
		add = (rand()%26+'A');
		block = block + add;
	}
	cout << block << endl;

	return 0;
}
