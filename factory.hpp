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
		//bool isop = false;


		while (i < length) {
			
			/*if (*input[i] == '1' || *input[i] == '2' || *input[i] == '3' || *input[i] == '4' || *input[i] == '5'
				|| *input[i] == '6' || *input[i] == '7' || *input[i] == '8' || *input[i] == '9' || *input[i] == '0')
			{

				lop = new Op(std::stod(input[i++]));
			}*/
			if ((*input[i] == '-') && (*input[i+1] == '+' || *input[i + 1] == '*' || *input[i + 1] == '/' ))
			{
				//*input[i] = '-';
				lop = new Op(std::stod(input[i++]));
				
				//isop = true;
			}
			

			else if (*input[i] == '1' || *input[i] == '2' || *input[i] == '3' || *input[i] == '4' || *input[i] == '5'
				|| *input[i] == '6' || *input[i] == '7' || *input[i] == '8' || *input[i] == '9' || *input[i] == '0')
			{
				lop = new Op(std::stod(input[i++]));
			}
			/*if (std::isdigit(std::stoi(input[i])) == 0) {
				lop = new Op(std::stod(input[i++]));
			}*/
			else {
				lop = rop;
			}
			if (*input[i] == '+') {
				root = new Add(lop, new Op(std::stod(input[++i])));
				rop = root;

				//isop = false;
			}
			else if (*input[i] == '-') {
				root = new Sub(lop, new Op(std::stod(input[++i])));
				rop = root;
				//isop = false;
			}
			else if (*input[i] == '/') {
				root = new Div(lop, new Op(std::stod(input[++i])));
				rop = root;
				//isop = false;
			}
			else if (*input[i] == '*') {
				if (*input[i + 1] == '*') {
					++i;
					root = new Pow(lop, new Op(std::stod(input[++i])));
					rop = root;
					//isop = false;
					
				}
				else {
					root = new Mult(lop, new Op(std::stod(input[++i])));
					rop = root;
					//isop = false;
				}
			}
		    /*else if (*input[i] == '**') {
				root = new Pow(lop, new Op(std::stod(input[++i])));
				rop = root;
				}*/
			else {
				std::cout << "ERROR, " << input[i] << " IS NOT A VALID INPUT" << std::endl;
				return nullptr;
			}
			++i;
		}
		return root;
	}
};

#endif // 