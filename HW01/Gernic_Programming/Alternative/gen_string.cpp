#include<iostream>
#include<string>
#include<algorithm>
#include<rand.h>

using namespace std;

void usage(string str){

	cout << "Usage: " << str << " <lines>" << " <len>" << endl;
}

int main(int argc, char const *argv[]){
	
	if(argc != 3){

		usage(argv[0]);
		exit(1);
	}

	init_randseed();

	int lines = atoi(argv[1]);
	int len   = atoi(argv[2]);

	string tmp = argv[1];
	string tmp2 = argv[2];

	string file = "randString_"+tmp+"_"+tmp2+".txt";

	gen_to_file(file, lines, len);

	return 0;
}