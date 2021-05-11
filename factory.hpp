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
			//if (std::isdigit(std::stoi(input[i])) == 0) {
			if (input[i] == "0" || input[i] == "1" || input[i] == "2" || input[i] == "3" || input[i] == "4" || input[i] == "5" ||
					input[i] == "6" || input[i] == "7" || input[i] == "8" || input[i] == "9") {
				lop = new Op(std::stod(input[i++]));
			}
			else {
				lop = rop;
			}
			if (input[i] == "+") {
				root = new Add(lop, new Op(std::stod(input[++i])));
				rop = root;
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