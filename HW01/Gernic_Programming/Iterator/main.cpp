#include<iostream>
#include<iomanip>
#include<iterator>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdio>

using namespace std;

#define TIME_TEST

#include<rand.h>
#include<calTime.h>

class line_iterator//for input
{
    istream*  in;
    string   line;
    bool     at_end;

    void read( ) {
        if (*in)//!NULL
            getline(*in, line);
        at_end = (*in) ? true : false;
    }

public:
    typedef  input_iterator_tag  iterator_category;
    typedef  string  value_type;
    typedef  ptrdiff_t  difference_type;
    typedef  const string*  pointer;
    typedef  const string&  reference;

    //line_iterator( ) : in(&cin), at_end(false) { }
    line_iterator(){

        in = &cin;
        at_end = false;
    }
    line_iterator(istream& s) : in(&s) { read( ); }
    reference operator*( ) const { return line; }
    pointer operator->( ) const { return &line; }

    line_iterator operator++( ) {  // prefix ++
        read( );
        return *this;
    }

    line_iterator operator++(int) {  // postfix ++
        line_iterator  tmp = *this;
        read();
        return tmp;
    }

    bool operator==(const line_iterator& i) const {
        return (in == i.in && at_end == i.at_end) ||
               (at_end == false && i.at_end == false);
    }

    bool operator!=(const line_iterator& i) const {
        return !(*this == i);
    }
}; // end  of class line_iterator

void usage(string str){

    cout << "Usage: " << str << " fileName" << endl;
}

int  main(int argc, char const *argv[])
{   
    vector<float> time_list;
    vector<string> title_list;

    if(argc != 2){

        usage(argv[0]);
        exit(1);
    }

    string fileName = argv[1];
    int length = fileName.size();
    char arr[length+1];
    strcpy(arr, fileName.c_str());

    freopen(arr, "r", stdin);

    T_START();
    line_iterator  iter(cin);
    line_iterator  end_of_file;
    T_END();
    time_list.push_back(T_CAL_SEC());
    title_list.push_back("input");

    vector<string>  V(iter, end_of_file);

    T_START();
    sort( V.begin(), V.end() ); // sort( V.begin(), V.end(), greater<string>() );
    T_END();
    time_list.push_back(T_CAL_SEC());
    title_list.push_back("sort");

    T_START();
    copy( V.begin(), V.end(), ostream_iterator<string>(cout, "\n"));
    T_END();
    time_list.push_back(T_CAL_SEC());
    title_list.push_back("output");

    Print_Time(fileName,title_list,time_list);
    
    return 0;
}
