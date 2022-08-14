#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    RPNCalc rpn;
    rpn.run();
    cerr << "Thank you for using CalcYouLater." << endl;
    return 0;
}
