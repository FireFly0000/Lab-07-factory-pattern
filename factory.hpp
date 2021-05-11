#pragma once
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include <iostream>
#include <ctype.h> // isdigit()
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

class Factory
{
private:

public:
	Base* parse(const char* input[], int length)
	{
		int i = 0;
		Base* root = nullptr;
		Base* lop = nullptr;
		Base* rop = nullptr;


		while (i < length) {
			if (std::isdigit(std::stoi(input[i])) == 0) {
			//if (std::isdigit(std::stoi(input[i]))) {
				lop = new Op(std::stod(input[i++]));
			}
			if (input[i] == "+") {
				root = new Add(lop, new Op(std::stod(input[++i])));
			}
			else {
				std::cout << "ERROR, INVALID INPUTS" << std::endl;
				return nullptr;
			}
			++i;
		}
		return root;
	}
};

#endif // 
