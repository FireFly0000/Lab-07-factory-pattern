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

int main(int argc, char* argv[]) {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab

    Factory test;
    const char* args[100];
    for (int i = 0; i < argc - 1; ++i) {
        args[i] = argv[i + 1];
    }

    Base* op = test.parse(args, argc - 1);

    for (int i = 0; i < argc - 1; ++i) {
        cout << args[i];
    }
    
    if (op == nullptr) {
        cout << " = Invalid Input Entered" << endl;
    }
    else {
        cout << " = " << op->evaluate() << endl;
    }

    /*Base* three = new Op(3);
    Base* seven = new Op(7.0);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;*/
    return 0;
}
