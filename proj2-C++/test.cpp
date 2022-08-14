#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    RPNCalc rpn;
    std::istringstream is("{ 1 2 + } { 1 2 + } { 1 2 + } }");
    cout << rpn.parseRString(is);
    return 0;
}