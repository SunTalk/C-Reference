#include<iostream>
#include<iomanip>
#include<iterator>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

#define TIME_TEST

#include<rand.h>
#include<calTime.h>

void usage(string str){

    cout << "Usage: " << str << "fileName" << endl;
}

int main(int argc, char const *argv[]){

    if(argc != 2){

        usage(argv[0]);
        exit(1);
    }

    string fileName = argv[1];
    int length = fileName.size();
    char arr[length+1];
    strcpy(arr, fileName.c_str());

    freopen(arr, "r", stdin);

    vector<string> v;
    string tmp;

    T_START();
    while(getline(cin, tmp))
        v.push_back(tmp);
    T_END();

    T_OUT();

    T_START();
    sort(v.begin(), v.end());
    T_END();

    T_OUT();

    T_START();
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n") );
    T_END();

    T_OUT();
    PUTCHAR();

    return 0;
}

