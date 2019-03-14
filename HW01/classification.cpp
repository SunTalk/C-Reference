#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("Alternative_list.list","r",stdin);
	freopen("Alternative.data","w",stdout);

	string target;
	string tmp;
	float num;
	float table[20][5];
	int count = 1;
	memset(table,0,sizeof(table));

	while( cin >> target ){
		if( target[0] == 'r' ){
			cin >> tmp >> num;
			table[count][0] += num;
			cin >> tmp >> num;
			table[count][1] += num;
			cin >> tmp >> num;
			table[count][2] += num;
			cin >> tmp >> num;
			table[count][3] += num;
			cin >> tmp >> num;
			table[count][4] += num;
			count++;

			if(count == 19)
				count=1;
		}
	}

	int one[6] = {1000,5000,10000,50000,100000,500000};
	int two[3] = {100,500,1000};

	count = 1;
	for(int i = 0 ; i < 6 ; i++ ){
		for(int j = 0 ; j < 3 ; j++ ){
			printf("%d X %d\n",one[i],two[j] );
			printf("input         %f\n",table[count][0]/100 );
			printf("CharTable     %f\n",table[count][1]/100 );
			printf("sort          %f\n",table[count][2]/100 );
			printf("output        %f\n",table[count][3]/100 );
			printf("total         %f\n",table[count][4]/100 );
			// printf("input         %f\n",table[count][0]/100 );
			// printf("sort          %f\n",table[count][1]/100 );
			// printf("output        %f\n",table[count][2]/100 );
			// printf("total         %f\n",table[count][3]/100 );
			printf("\n");
			count++;
		}
	}


	return 0;
}