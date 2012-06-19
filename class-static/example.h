#include <iostream>
#include <string.h>
using namespace std;

class Foo {
public:
   Foo();
   char* display(char *s);	
   string helloString(string s); 
   void setMe(int &x) { x = 9; } // Passing by reference
   static void printMe();
};


