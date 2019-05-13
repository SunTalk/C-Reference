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
	bool operator()(const pair<string,int>& lhs, const pair<string,int>& rhs){

		if(mode == NORMAL){

			return lhs.second < rhs.second;
		}
		else{

			return lhs.second > rhs.second;
		}
	}


private:
	bool mode;

};

struct CmpByValue {
  bool operator()(const pair<string,int>& lhs, const pair<string,int>& rhs) {
    return lhs.second > rhs.second;
  }
};

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("HW03.in","r",stdin);
	freopen("HW03.out","w",stdout);
	#endif

	multimap <string, string> data;
	int num;
	scanf("%d",&num);
	string name,block,payload;

	for(int i = 0 ; i < num ; i++ ){
		cin >> name >> block ;
		data.insert(make_pair(name,block));
	}
	cin >> payload;

	multimap<string,string>::iterator multi_i;

	map <string,int> table;

	for(auto &multi_i : data){

		table.insert(make_pair((multi_i).first, 0));
		if((multi_i).second.find(payload, 0) != string::npos){

			table.find((multi_i).first)->second++;
		}
	}	


	// for(multi_i = data.begin(); multi_i != data.end() ; multi_i++ ){
	// 	table.insert( make_pair((*multi_i).first,0) );
	// 	if( (*multi_i).second.find(payload,0) != string::npos ){
	// 		table.find( (*multi_i).first )->second++;
	// 	}
	// }

	vector < pair<string,int> > V(table.begin(), table.end());
	sort(V.begin(), V.end(), RuntimeCMP(RuntimeCMP::CMP_GREAT));

	for(int i = 0 ; i < V.size() ; i++ ){
		if( V[i].second > 0 )
			cout << V[i].first << " " << "Y " << V[i].second << "\n" ;
		else
			cout << V[i].first << " " << "N\n";
	}

	return 0;
}