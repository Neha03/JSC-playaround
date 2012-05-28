#include<iostream>
using namespace std;
#include "Test.h"
#define M_PI 3.14159

int Circle::area(int r) {
cout<<"Circle::area called"<<endl;
return M_PI*r*r;
}

