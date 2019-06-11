#include <bits/stdc++.h>
using namespace std;

bool is_IP(const string &ip ){
	auto pattern = R"(^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$)";
	regex IP(pattern);
	return regex_match(ip,IP);
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string str;
	while( cin >> str )
		cout << (is_IP(str) ? "TRUE\n" : "FALSE\n") ;

	return 0;
}