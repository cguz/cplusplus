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

// Single-Responsibility Principle: 
// A class should have one and only one reason to change, meaning that a class should have only one job.
// In SOLID principle, it is better to separate the responsability.
// Thus, we do not implement the save method in the class but in another class.
// with this approach we have all the persistence code in one place

// the Journal keeps track of the entries, but another class persist all the entries
struct Journal {
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title){}

    void add_entry(const string& entry){
        static int count = 1;
        entries.push_back(std::to_string(count++) + ": " + entry);
    }

};

// Persist all the Journals
struct PersistenceManager {

    void save(const Journal& j, const string& filename){
        ofstream ofs(filename);
        for (auto& e: j.entries){
            ofs << e << endl;
        }
    }
};

int main(){

    Journal journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");

    getchar();
    return 0;
}