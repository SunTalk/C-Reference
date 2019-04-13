#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	freopen("g2.data","r",stdin);
	freopen("p2.out","w",stdout);

	int page,num;
	scanf("%d %d",&page,&num);
	string str;
	cin >> str;
	int table[10];
	memset(table,0,sizeof(table));
	for(int i = 0 ; i < str.size() ; i++ )
		table[str[i]-'0']++;

	int wh_page,wh_num,pa;
	int ans;
	string check = "";
	while( ~scanf("%d %d %d",&wh_page,&wh_num,&pa) ){
		wh_page--;
		wh_num--;
		check = check + str[wh_page*num+wh_num];
		ans = str[wh_page*num+wh_num] - '0';
		printf("%d %d %d\n",ans ,table[ans] ,table[ans]%pa );
	}

	ans = 0;
	cout << check ;
	string tmp;
	string remember = check;
	next_permutation(check.begin(), check.end());
	
	while( check != remember ){
		for(int i = 0 ; i <= str.size()-check.size() ; i++ ){
			tmp = str.substr(i,check.size());
			if( tmp == check )
				ans++;
		}
		next_permutation(check.begin(), check.end());
	}	

	printf(" %d\n",ans );

	return 0;
}