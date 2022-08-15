#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

// I avoid the use of boost library by creating the to_string method inside the std library.
std::string to_string( int x ) {
    int length = snprintf( NULL, 0, "%d", x );
    assert( length >= 0 );
    char* buf = new char[length + 1];
    snprintf( buf, length + 1, "%d", x );
    std::string str( buf );
    delete[] buf;
    return str;
}

int main(){

    

    return 0;
}