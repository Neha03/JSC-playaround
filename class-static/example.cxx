#include "example.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Foo::Foo() {
    cout<<"-------------- Foo C++ object created"<<endl;
}

char *Foo::display(char *s) {
	char *str = (char *)malloc(256*sizeof(char));  
	strcpy(str, s);
  	strcat(str, "...This is C++");
	return str;
}

string Foo::helloString(string s) {
	string newstr = "Hello " + s;
	return newstr;
}

void Foo::printMe() {
  cout<<"Hello! this is a static function and my name is Foo"<<endl;
}


