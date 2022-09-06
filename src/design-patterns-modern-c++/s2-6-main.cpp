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

// Interface Segregation Principle: Clients should not be forced to depend upon interfaces that they do not use.

struct Document;

// struct IMachine {
//     virtual void print(Document& doc) = 0;
//     virtual void scan(Document& doc) = 0;
//     virtual void fax(Document& doc) = 0;
// };

// struct MFP : IMachine{
//     void print(Document &doc) override {
        
//     }
//     void scan(Document &doc) override {
        
//     }
//     void fax(Document &doc) override {
        
//     }
// };

// struct Scanner : IMachine{
//     void print(Document &doc) override {
        
//     }
//     void scan(Document &doc) override {
        
//     }
//     void fax(Document &doc) override {
        
//     }
// };

// The previous problem we solve with the Interface Segregation Principle as follow: 

// 1. Recompile
// 2. Client does not need this
// 3. Forcing implementors to implement too much

struct IPrinter
{
  virtual void print(Document& doc) = 0;
};

struct IScanner
{
  virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter
{
  void print(Document& doc) override;
};

struct Scanner : IScanner
{
  void scan(Document& doc) override;
};

struct IMachine: IPrinter, IScanner
{
};

struct Machine : IMachine
{
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner) : printer{printer},scanner{scanner}
  {
  }

  void print(Document& doc) override {
    printer.print(doc);
  }
  void scan(Document& doc) override {
    scanner.scan(doc);
  }
};

// IPrinter --> Printer
// everything --> Machine


int main(){

    getchar();
    return 0;
}