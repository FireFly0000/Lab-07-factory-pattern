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
	Base* root = nullptr;
	bool neg(char* input[], int i){
    		if( input[i][0] == '-'){
        		return true;
    		}
    		else return false;
	}
	bool not_1_decimal(char* input[], int i){
    		int c = 0;
    		for(int j =0; j<strlen(input[i]); j++){
        		if(input[i][j] == '.'){
            			c++;
        		}
    		}
    		if(c >1){
        		return true;
    		}
    		else return false;
	}
	bool is_double(char* input[], int i){
                bool res;
                if(input[i] != "**" && input[i] != "+" &&  input[i] != "-" &&  input[i] != "*" &&  input[i] != "/"){
                        for(int j =0; j<strlen(input[i]); j++){
                                if(!isdigit(input[i][j]) && j == 0 && !neg(input,i) ){
                                        return false;
                                }
                                if((j>0 && j<strlen(input[i])) && !isdigit(input[i][j]) && input[i][j] != '.' ){
                                        return false;
                                }
                                if(not_1_decimal(input,i)){
                                    return false;
                                }
                                if(j == strlen(input[i])-1 && input[i][j] =='.'){
                                    return false;
                                }
                        }
                        return true;
                }
                return false;
        }
	std::string error(){
		std::string res = "ERROR, INVALID INPUTS\n";
		return res;
	}
			
public:
	~Factory(){
		delete root;
	}
	Base* parse(char* input[], int length)
	{
		int i = 0;
		//Base* root = nullptr;
		Base* lop = nullptr;
		Base* rop = nullptr;
				
		while (i < length) {
			
			if(is_double(input,i)){
				lop = new Op(std::stod(input[i++]));
			}
			else {
				lop = rop;
			}
			if (input[i] == "+") {
				i++;
				if(is_double(input,i)){
					root = new Add(lop, new Op(std::stod(input[i])));
					rop = root;
				}
				else{
					std::cout << error();
					return nullptr;
				}
			}
			else if (input[i] == "-") {
				i++;
				if(is_double(input,i)){
					root = new Sub(lop, new Op(std::stod(input[i])));
					rop = root;
				}
				else{
					std::cout << error();
					return nullptr;
				}
			}
			else if (input[i] == "/") {
				i++;
				if(is_double(input,i)){
					root = new Div(lop, new Op(std::stod(input[i])));
					rop = root;
				}
				else{
                                        std::cout << error();
                                        return nullptr;
                                }

			}
			else if (input[i] == "*") {
				i++;
				if(is_double(input,i)){
					root = new Mult(lop, new Op(std::stod(input[i])));
					rop = root;
				}
				else{
					std::cout << error();
                                        return nullptr;
                                }

			}
			else if (input[i] == "**") {
				i++;
				if(is_double(input,i)){
					root = new Pow(lop, new Op(std::stod(input[i])));
					rop = root;
				}
				else{
					std::cout << error();
                                        return nullptr;
                                }

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
