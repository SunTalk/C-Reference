#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int page,num;
	scanf("%d %d\n",&page,&num);
	string str;
	cin >> str;
	int ans,wh_page,wh_num,pa;
	string check = "";
	while( ~scanf("%d %d %d",&wh_page,&wh_num,&pa) ){
		check = check + str[(wh_page-1)*num+(wh_num-1)];
		ans = str[(wh_page-1)*num+(wh_num-1)] - '0';
		printf("%d %d %d\n",ans ,count(str.begin(), str.end(),ans+'0') ,count(str.begin(), str.end(),ans+'0')%pa );
	}
	cout << check ;
	ans = 0;
	for(int i = 0 ; i < str.size() ; i++ )
		if( is_permutation(check.begin(), check.end(), &str[i] ) )
			ans++;
	printf(" %d\n",ans );
	
	return 0;
}