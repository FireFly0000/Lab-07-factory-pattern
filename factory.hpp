#pragma once
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include <iostream>
#include <ctype.h> // isdigit()
#include <cstring> //for strlen()
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
		bool is_double = false;
		bool neg = false;

		while (i < length) {
			//if (std::isdigit(std::stoi(input[i])) == 0) {
			/*if (input[i][0] == '-'){
				neg = true;
			}
			for(int j =0; j<strlen(input[i]); j++){
				if(input[i][j] == '-' || isdigit(input[i][j])){
					is_double = true;
				}
				else is_double = false;
			}
			if(is_double && !neg){
				lop = new Op(std::stod(input[i++]));
			}
			else if(is_double && neg){
				double temp = std::stod(input[i++]);
				lop = new Op(-temp);
			}*/
			else {
				lop = rop;
			}
			if (input[i] == "+") {
				root = new Add(lop, new Op(std::stod(input[++i])));
				rop = root;
			}
			else if (input[i] == "-") {
				root = new Sub(lop, new Op(std::stod(input[++i])));
				rop = root;
			}
			else if (input[i] == "/") {
				root = new Div(lop, new Op(std::stod(input[++i])));
				rop = root;
			}
			else if (input[i] == "*") {
				//if (input[i+1] == "*")
				root = new Mult(lop, new Op(std::stod(input[++i])));
				rop = root;
			}
			else if (input[i] == "**") {
				root = new Pow(lop, new Op(std::stod(input[++i])));
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
