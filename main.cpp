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

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab

    Factory test;
    const char* args[] = { "3", "+", "7", "+", "10","+","20","+","40"}; // TODO FIX: doesn't work in descending order { "40", "+", "20", "+", "10","+","7","+","3"}; op = nullptr?
    Base* op = test.parse(args, 9);                                                         

    for (int i = 0; i < 9; ++i) {
        cout << args[i];
    }
    cout << " = " << op->evaluate() << endl;


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
