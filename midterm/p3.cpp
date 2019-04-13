#include <bits/stdc++.h>
using namespace std;

class student{
public:

	string name;
	int g_english,g_math;

	friend ostream& operator<<(ostream& out, const student &st){
		out << st.name << " " << st.g_english << " " << st.g_math ;
		return out;
	}
	friend istream& operator>>(istream& in, student &st){
		in >> st.name >> st.g_english >> st.g_math;
		return in;
	}

	friend bool operator<(const student& lhs, const student& rhs){
		int L = lhs.total();
		int R = rhs.total();
		if( L == R )
			return lhs.name < rhs.name;
		return L < R;
	}
	
	friend bool operator>(const student& lhs, const student& rhs){
		int L = lhs.total();
		int R = rhs.total();
		if( L == R )
			return lhs.name > rhs.name;
		return L > R;
	}

	int total() const{
		return g_english+g_math;
	}

};

enum{
	LESS,
	GREATER
};

template <int T>
class RuntimeCmp{
public:
	bool operator()(const student lhs, const student rhs ){
		if (T == LESS)
			return lhs < rhs;
		else
			return lhs > rhs;
	}
};

int main(int argc, char const *argv[])
{
	
	freopen("p3.in","r",stdin);
	freopen("p3.out","w",stdout);

	int num;
	scanf("%d",&num);

	set <student, RuntimeCmp<LESS> > A;
	set <student, RuntimeCmp<GREATER> > B;

	student tmp;
	while( num-- ){
		cin >> tmp;
		A.insert(tmp);
		B.insert(tmp);
	}

	cout << "Set A:" << endl;
	for(auto &i : A)
		cout << i << endl;
	cout << endl;
	cout << "Set B:" << endl;
	for(auto &i : B)
		cout << i << endl;

	return 0;
}