/*
 *  DatumStack.cpp
 *  Brandon Shih
 *  3/8/22
 *
 *  COMP 15 Proj2 RPNCalc
 *
 *  This class is a stack for objects called datum which can hold an
 *  integer, bool, char, or an rstring. It also contains various functions
 *  to access different information about the datum stack or make changes
 *  to it.
 */

#ifndef _DATUMSTACK_H_
#define _DATUMSTACK_H_

#include "Datum.h"
#include <list>

class DatumStack {
    public:
        DatumStack();
        DatumStack(Datum data[], int arrSize);
        bool isEmpty();
        void clear();
        int size();
        Datum top();
        void pop();
        void push(Datum d);
    private:
        std::list<Datum> datumStack;
};

#endif