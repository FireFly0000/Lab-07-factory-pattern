#pragma once
#include <iostream>

//#include "base.hpp"
#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "factory.hpp"

using namespace std;

int main(int argc, char**argv) {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab

    Factory test;
    //char* args[] = { "-14.2", "**", "3", "-", "-32", "+", "16", "/", "2", "*", "3"}; 
    //char* args[] = { "4", "+", "3"};
    //Base* op = test.parse(args, 11);                                                       
    
    //cout << op->stringify();
    //cout << " = " << op->evaluate() << endl;
    

 
    char* args[argc-1];
    for(unsigned i = 1; i < argc-1; i++){
	args[i] = argv[i];
    }
    for (int i = 0; i < argc-1; ++i) {
    	cout << args[i];
    }		
    cout << endl;
    //Base* op = test.parse(args, argc);

    //cout << " = " << op->evaluate();
    cout << endl;
   
//=================================== 
   /* Factory* Test = new Factory();
    
    for(unsigned i = 0; i < argc; i++) {
      cout << argv[i];
    }

    Base* op = Test->parse(argv, argc);
    if(!op) {
      cout << "invalid expression Tree" << endl;
    } else {
      cout << op->stringify() << " = " << op->evaluate() << endl;
    }
    delete Test;*/

    return 0;
}
