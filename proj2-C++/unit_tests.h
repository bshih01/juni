#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <iostream>

// TESTING FOR DATUMSTACK

// Testing the empty datum stack constructor by using toString and size
void testEmptyDatumStackConstructor() {
    DatumStack stack;
    Datum datumInt(1);
    stack.push(datumInt);
    assert(stack.top().toString() == "1");
    assert(stack.size() == 1);
}
// Testing the array datum stack constructor
void testDatumStackConstructor() {
    Datum datumInt(1);
    Datum datumBool(true);
    Datum datumString("{ 2 8 + }");
    Datum datumChar('a');
    Datum data[4] = {datumInt, datumBool, datumChar, datumString};
    DatumStack stack(data, 4);
    assert(stack.size() == 4);
    assert(stack.top().toString() == "{ 2 8 + }");
}
// Testing the datum stack size and isEmpty
void testDatumStackSizeAndEmpty() {
    DatumStack stack;
    assert(stack.isEmpty());
    Datum datumInt(1);
    assert(stack.size() == 0);
    stack.push(datumInt);
    assert(stack.size() == 1);
    stack.push(datumInt);
    assert(stack.size() == 2);
}
// Testing the datum stack clear function
void testDatumStackClear() {
    Datum datumInt(1);
    Datum data[4] = {datumInt, datumInt, datumInt, datumInt};
    DatumStack stack(data, 4);
    assert(stack.size() == 4);
    stack.clear();
    assert(stack.isEmpty());
}
// Testing the datum stack top function
void testDatumStackTop() {
    Datum datumInt1(1);
    Datum datumInt2(2);
    Datum data[2] = {datumInt1, datumInt2};
    DatumStack stack(data, 2);
    assert(stack.top().toString() == "2");
}
// Testing the datum stack top exception
void testDatumStackTopExcep() {
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        DatumStack stack;
        stack.top();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "empty_stack");
}
// Testing the datum stack pop function
void testDatumStackPop() {
    Datum datumInt1(1);
    Datum datumInt2(2);
    Datum data[2] = {datumInt1, datumInt2};
    DatumStack stack(data, 2);
    assert(stack.top().toString() == "2");
    stack.pop();
    assert(stack.top().toString() == "1");
}
// Testing the datum stack pop exception
void testDatumStackPopExcep() {
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        DatumStack stack;
        stack.pop();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "empty_stack");
}
// Testing the datum stack push function
void testDatumStackPush() {
    DatumStack stack;
    assert(stack.size() == 0);
    Datum d(1);
    stack.push(d);
    assert(stack.size() == 1);
    assert(stack.top().getInt() == 1);
}
/*
// TESTING FOR RPNCALC. TESTED BY MAKING PRIVATE MEMBERS PUBLIC

// Testing default constructor RPNCalc
void testDefaultConstructorRPN() {
    RPNCalc rpn;
    assert(rpn.DS.size() == 0);
}
// Testing the intCMD RPNCalc
void testIntCMD() {
    RPNCalc rpn;
    int i = 1;
    int *I = &i;
    rpn.intCMD(*I);
    assert(rpn.DS.top().getInt() == 1);
}
// Testing the ftBoolCMDs RPNCalc
void testFTBoolCMD() {
    RPNCalc rpn;
    rpn.fBoolCMD();
    assert(rpn.DS.top().getBool() == false);
    rpn.tBoolCMD();
    assert(rpn.DS.top().getBool() == true);
}
//Testing the notCMD RPNCalc
void testNotCMD() {
    RPNCalc rpn;
    rpn.fBoolCMD();
    assert(rpn.DS.top().getBool() == false);
    rpn.notCMD();
    assert(rpn.DS.top().getBool() == true);
}
// Testing if top isn't a bool
void testNotCMDExcepNotBool() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        int i = 1;
        int *I = &i;
        rpn.intCMD(*I);
        rpn.notCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    // checking if exception has already been caught
    assert(runtime_error_thrown);
}
// Testing notCMD if it is empty
void testNotCMDExcepEmpty() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.notCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing printCMD
void testPrintCMD() {
    RPNCalc rpn;
    rpn.fBoolCMD();
    rpn.printCMD();
}
// Testing if is empty
void testPrintCMDExcep() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.printCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing clearCMD
void testClearCMD() {
    RPNCalc rpn;
    rpn.fBoolCMD();
    assert(rpn.DS.size() == 1);
    rpn.DS.clear();
    assert(rpn.DS.size() == 0);
}
// Testing dropCMD
void testDropCMD() {
    RPNCalc rpn;
    rpn.fBoolCMD();
    rpn.tBoolCMD();
    assert(rpn.DS.top().getBool() == true);
    rpn.DS.pop();
    assert(rpn.DS.top().getBool() == false);
}
// Testing dropCMD empty exception
void testDropCMDExcep() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.DS.pop();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing the dupCMD
void testDupCMD() {
    RPNCalc rpn;
    rpn.tBoolCMD();
    assert(rpn.DS.top().getBool() == true);
    rpn.DS.push(rpn.DS.top());
    assert(rpn.DS.top().getBool() == true);
    assert(rpn.DS.size() == 2);
    rpn.DS.pop();
    assert(rpn.DS.top().getBool() == true);
}
// Testing dupCMD empty exception
void testDupCMDExcep() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.DS.push(rpn.DS.top());
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing the swapCMD
void testSwapCMD() {
    RPNCalc rpn;
    rpn.tBoolCMD();
    rpn.fBoolCMD();
    assert(rpn.DS.top().getBool() == false);
    rpn.swapCMD();
    assert(rpn.DS.top().getBool() == true);
    assert(rpn.DS.size() == 2);
    rpn.DS.pop();
    assert(rpn.DS.top().getBool() == false);
}
// Testing the swapCMD 1 or 0 size
void testSwapCMDExcep() {
    // testing for empty
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.swapCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
    // testing for when size == 1
    runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.swapCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing the operCMD
void testOperCMD() {
    RPNCalc rpn;
    // making integer pointers to make int datums
    int i = 1;
    int j = 2;
    int *I = &i;
    int *J = &j;
    rpn.intCMD(*I);
    rpn.intCMD(*J);
    rpn.operCMD("+");
    assert(rpn.DS.top().getInt() == 3);
}
// Testing the operCMD with 0 or 1 integers on top
void testOperCMDExcepEmpty() {
    // testing for empty stack
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.operCMD("+");
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
    // testing for when size == 1
    runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        int i = 1;
        int *I = &i;
        rpn.intCMD(*I);
        rpn.operCMD("+");
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing the operCMD when the top two aren't integers
void testOperCMDExcepNotInt() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.fBoolCMD();
        rpn.operCMD("-");
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing the ineqCMD
void testineqCMD() {
    RPNCalc rpn;
    int i = 1;
    int j = 2;
    int *I = &i;
    int *J = &j;
    rpn.intCMD(*I);
    rpn.intCMD(*J);
    rpn.ineqCMD("<");
    assert(rpn.DS.top().getBool() == true);
}
// Testing the ineqCMD with 0 or 1 integers on top
void testIneqCMDExcepEmpty() {
    // testing for empty stack
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.ineqCMD("==");
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
    // testing for when size == 1
    runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        // making integer pointer to make int datums
        int i = 1;
        int *I = &i;
        rpn.intCMD(*I);
        rpn.ineqCMD("<=");
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing the ineqCMD when the top two aren't integers
void testIneqCMDExcepNotInt() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.fBoolCMD();
        rpn.ineqCMD(">");
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing rstringCMD
void testRStringCMD() {
    RPNCalc rpn;
    rpn.rstringCMD("{ 1 2 + }");
    assert(rpn.DS.top().getRString() == "{ 1 2 + }");
}
// Testing execCMD
void testExecCMD() {
    // execute on operations
    RPNCalc rpn;
    rpn.rstringCMD("{ 1 2 + }");
    rpn.execCMD();
    assert(rpn.DS.top().getInt() == 3);
    // execute on boolean
    rpn.rstringCMD("{ #t }");
    rpn.execCMD();
    assert(rpn.DS.top().getBool() == true);
    // execute on rstrings
    rpn.rstringCMD("{ { 2 3 - } { 1 2 * } }");
    // execute on nested rstring
    rpn.execCMD();
    assert(rpn.DS.top().getRString() == "{ 1 2 * }");
}
// Testing execCMD on empty stack
void testExecCMDExcepEmpty() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.execCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing execCMD on nonrstring (Used to test older code)
void testExecCMDExcepNotRString() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.execCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing fileCMD
void testFileCMD() {
    RPNCalc rpn;
    // making integer pointer to make int datums
    int i = 4;
    int *I = &i;
    rpn.intCMD(*I);
    // applying the factorial file on 4 to get 24
    rpn.rstringCMD("{ fact.cylc }");
    rpn.fileCMD();
    assert(rpn.DS.top().getInt() == 24);
}
// Testing fileCMD on empty stack
void testFileCMDExcepEmpty() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.fileCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing fileCMD on nonrstring top (Used to test older code)
void testFileCMDExcepNotRString() {
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.fileCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing fileCMD on nonexistent file
void testFileCMDBrokenFile() {
    RPNCalc rpn;
    rpn.rstringCMD("{ fail.cyl }");
    // should print to cerr: "Error: Unable to read fail.cyl"
    rpn.fileCMD();
}
// Testing ifCMD
void testIfCMD() {
    RPNCalc rpn;
    // checking true condition
    rpn.tBoolCMD();
    rpn.rstringCMD("{ 1 }");
    rpn.rstringCMD("{ 2 }");
    rpn.ifCMD();
    assert(rpn.DS.top().getInt() == 1);
    rpn.DS.clear();
    // checking false condition
    rpn.fBoolCMD();
    rpn.rstringCMD("{ 1 }");
    rpn.rstringCMD("{ 2 }");
    rpn.ifCMD();
    assert(rpn.DS.top().getInt() == 2);
}
// Testing ifCMD on empty stack size 0, 1, 2
void testIfCMDExcepEmpty() {
    // testing for size == 0
    bool runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.ifCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    // if ifCMD catches it, the catch won't be entered
    assert(runtime_error_thrown);
    // testing for size == 1
    runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.ifCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
    // testing for size == 2
    runtime_error_thrown = false;
    try {
        RPNCalc rpn;
        rpn.tBoolCMD();
        rpn.rstringCMD("{ 1 }");
        rpn.ifCMD();
    } catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
    }
    assert(runtime_error_thrown);
}
// Testing ifCMD with incorrect data types
void testIfCMDExcepWrongTypes() {
    RPNCalc rpn;
    // if on three rstrings
    rpn.rstringCMD("{ 1 }");
    rpn.rstringCMD("{ 2 }");
    rpn.rstringCMD("{ 3 }");
    rpn.ifCMD();
    rpn.DS.clear();
    // if on three integers
    int i = 1;
    int *I = &i;
    rpn.intCMD(*I);
    rpn.intCMD(*I);
    rpn.intCMD(*I);
    rpn.ifCMD();
}
// Testing showStackCMD
void testShowStackCMD() {
    RPNCalc rpn;
    rpn.rstringCMD("{ 1 }");
    rpn.rstringCMD("{ 2 }");
    rpn.rstringCMD("{ 3 }");
    // should print to cout
    rpn.showStackCMD();
}
// Testing parseRString
void testParseRString() {
    RPNCalc rpn;
    std::stringstream ss;
    ss << " 1 2 + }";
    assert(rpn.parseRString(ss) == "{ 1 2 + }");
    std::stringstream ss1;
    ss1 << " { 1 } { 2 } }";
    assert(rpn.parseRString(ss1) == "{ { 1 } { 2 } }");
}
// gotInt function provided by the cs15 department. Assuming gotInt works.

// Testing gotOp
void testGotOp() {
    RPNCalc rpn;
    assert(rpn.gotOp("+") == true);
    assert(rpn.gotOp("-") == true);
    assert(rpn.gotOp("*") == true);
    assert(rpn.gotOp("/") == true);
    assert(rpn.gotOp("mod") == true);
    assert(rpn.gotOp("a") == false);
}
// Testing gotEq
void testGotEq() {
    RPNCalc rpn;
    assert(rpn.gotEq("==") == true);
    assert(rpn.gotEq(">=") == true);
    assert(rpn.gotEq("<=") == true);
    assert(rpn.gotEq(">") == true);
    assert(rpn.gotEq("<") == true);
    assert(rpn.gotEq("a") == false);
}
// Testing run and runHelper in main by trying various inputs through std::cin
*/