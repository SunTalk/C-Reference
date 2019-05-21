#include <bits/stdc++.h>
using namespace std;

class RuntimeCMP{

public:

	static const bool CMP_GREAT = true;
	static const bool NORMAL   = false;

	RuntimeCMP(){

		mode = NORMAL;
	}

	RuntimeCMP(bool mode){

		this->mode = mode;
	}
	bool operator()(const string& lhs, const string& rhs){

		if(mode == NORMAL){

			return lhs < rhs;
		}
		else{

			return lhs > rhs;
		}
	}


private:
	bool mode;

};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	regex word("[A-Za-z]+");
	smatch find_word;

	string str;
	vector <string> ans;

	while( getline(cin,str) ){

		ans.clear();
		while( regex_search(str,find_word,word) ){
			ans.push_back(find_word[0]);
			str = find_word.suffix().str();
		}

		sort(ans.begin(), ans.end(),RuntimeCMP(RuntimeCMP::CMP_GREAT));

		for(auto &i : ans )
			cout << i << endl;

		printf("\n");

	}

	return 0;
}