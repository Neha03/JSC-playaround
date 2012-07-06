#!/bin/sh
gcc -c -I/usr/include/webkit-1.0 example.cpp example_wrap.cxx runme.cpp 
gcc -o runme example.o example_wrap.o runme.o -lwebkitgtk-1.0
