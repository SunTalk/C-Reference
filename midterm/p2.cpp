#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int page,num;
	scanf("%d %d\n",&page,&num);
	string str;
	cin >> str;
	int table[10];
	for(int i = 0 ; i < 10 ; i++ )
		table[i] = count(str.begin(), str.end(),i+'0');

	int ans,wh_page,wh_num,pa;
	string check = "";
	while( ~scanf("%d %d %d",&wh_page,&wh_num,&pa) ){
		check = check + str[(wh_page-1)*num+(wh_num-1)];
		ans = str[(wh_page-1)*num+(wh_num-1)] - '0';
		printf("%d %d %d\n",ans ,table[ans] ,table[ans]%pa );
	}
	cout << check ;

	ans = 0;
	string remember = check;
	do{
		int tmp = str.find(check,0);
		while( tmp != -1 ){
			ans++;
			tmp = str.find(check,tmp+1);
		}
		next_permutation(check.begin(), check.end());

	}while( check != remember );
	printf(" %d\n",ans );

	return 0;
}