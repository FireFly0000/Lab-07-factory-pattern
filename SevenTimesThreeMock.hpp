#pragma once
#ifndef __SEVENTIMESTHREEMOCK_HPP__
#define __SEVENTIMESTHREEMOCK_HPP__

#include "base.hpp"

class SevenTimesThreeMock: public Base {
    public:
        SevenTimesThreeMock() { }

        virtual double evaluate() { return 21; }
        virtual std::string stringify() { return "(7*3)"; }
};
#endif //__SEVENTIMESTHREEMOCK_HPP__

