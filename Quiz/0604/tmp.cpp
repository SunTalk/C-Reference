#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int num,tmp;
	vector <int> table;
	vector <int> change;
	vector <int> three;
	vector <int> four;
	bool flag = false;
 	while( ~scanf("%d",&num) ){

 		if( flag )
	 		cout << endl;
	 	flag =true;

		table.clear();
		change.clear();
		three.clear();

		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&tmp);
			table.push_back(tmp);
		}
		change.resize(table.size()-1);
		three.resize(change.size());
		four.resize(three.size());

		auto T = table.begin();
		auto C = [&T](int k){
					return k -*T++;
				};
		auto P = [](int k){
					cout << " " << k;
				};
		auto CH = three.begin();
		auto TOTAL = [&CH](int k){
					return k+*CH++;
				};
		int MIN = 0;
		auto FOUR = [&MIN](int k){
						int A = k-MIN;
						if( MIN > k )
							MIN = k;
						return A;
					};
		int sub_arr=0,total=0;
		int START = 0;
		int TMP = 0;
		int END = 0;
		int RE = 0;
		auto SUB_ARR = [&sub_arr,&total,&START,&END,&TMP,&RE](int k){
							total = total+k;
							if( total < 0 ){
								total = 0;
								TMP = RE+1;
							}
							if( total > sub_arr ){
								sub_arr = total;
								START = TMP;
								END = RE;
							}
							RE++;
						};

		cout << table[0];
		for_each(table.begin()+1, table.end(),P);
		cout << endl;

		transform(table.begin()+1, table.end(),change.begin(),C);

		cout << change[0] ;
		for_each(change.begin()+1, change.end(),P);
		cout << endl;

		three[0] = change[0];
		transform(change.begin()+1, change.end(),three.begin()+1,TOTAL);

		cout << three[0] ;
		for_each(three.begin()+1, three.end(),P);
		cout << endl;

		transform(three.begin(),three.end(),four.begin(),FOUR);

		cout << four[0] ;
		for_each(four.begin()+1, four.end(),P);
		cout << endl;

		for_each(change.begin(), change.end(),SUB_ARR);
		cout << sub_arr << endl;

		cout << table[START] ;
		for_each(&table[START+1],&table[END+2],P);
		cout << endl;
		
	}

	return 0;
}