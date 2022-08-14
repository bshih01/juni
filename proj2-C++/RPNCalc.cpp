/*
 *  RPNCalc.cpp
 *  Brandon Shih
 *  3/8/22
 *
 *  COMP 15 Proj2 RPNCalc
 *
 *  This class uses the DatumStack class to manage the status of the
 *  calculator as it runs. This is because the program needs to use a
 *  LIFO method to compute operations in reverse polish notation. It is
 *  also helpful to use LIFO for the if statements and other commands.
 *  This class has one run function with many helpers to run the 
 *  calculator.
 */

#include "RPNCalc.h"
#include "Datum.h"
#include "DatumStack.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
Name: RPNCalc
Purpose: Constructor for RPNCalc class object. Initializes the RPN simulation.
Arguments: No arguments.
Returns: No returns.
Effects: No values changed.
*/
RPNCalc::RPNCalc() {}
/*
Name: ~RPNCalc
Purpose: Destructor for RPNCalc class object. Recycles the memory used by RPN.
Arguments: No arguments.
Returns: No returns.
Effects: All data stored in the DatumStack is recycled.
*/
RPNCalc::~RPNCalc() {}
/*
Name: run
Purpose: Runs the RPN calculator with the help of many helper functions.
Arguments: No arguments.
Returns: No returns.
Effects: Adds, removes, changes data in the DatumStack depending on commands.
*/
void RPNCalc::run() {
    runHelper(std::cin);
}

// private helper command functions for run

/*
Name: intCMD
Purpose: Pushes an integer datum onto the datum stack
Arguments: int &I which is the address of the integer being pushed
Returns: No returns.
Effects: Size of datum stack increases by 1, and a new integer datum is added.
*/
void RPNCalc::intCMD(int &I) {
    Datum d(I);
    DS.push(d);
}
/*
Name: tBoolCMD
Purpose: Pushes an true bool datum onto the datum stack
Arguments: No arguments.
Returns: No returns.
Effects: Size of datum stack increases by 1, and a new true bool datum added.
*/
void RPNCalc::tBoolCMD() {
    Datum d(true);
    DS.push(d);
}
/*
Name: fBoolCMD
Purpose: Pushes an false bool datum onto the datum stack
Arguments: No arguments.
Returns: No returns.
Effects: Size of datum stack increases by 1, and a new false bool datum added.
*/
void RPNCalc::fBoolCMD() {
    Datum d(false);
    DS.push(d);
}
/*
Name: notCMD
Purpose: Switches the top bool to the opposite.
Arguments: No arguments.
Returns: No returns.
Effects: Top bool is negated.
*/
void RPNCalc::notCMD() {
    // determining how to negate the bool and doing so
    Datum d(DS.top());
    dropCMD();
    // determining how to negate the bool and doing so
    if (d.getBool()) {
        fBoolCMD();
    } else if (d.getBool() == false) {
        tBoolCMD();
    }
}
/*
Name: printCMD
Purpose: Prints out the top datum in string form.
Arguments: No arguments.
Returns: No returns.
Effects: No values changed.
*/
void RPNCalc::printCMD() {
    std::cout << DS.top().toString() << std::endl;
}
/*
Name: clearCMD
Purpose: Removes everything from the datum stack.
Arguments: No arguments.
Returns: No returns.
Effects: Size is set to 0. All data is removed.
*/
void RPNCalc::clearCMD() {
    DS.clear();
}
/*
Name: dropCMD
Purpose: Removes the top datum from the datum stack.
Arguments: No arguments.
Returns: No returns.
Effects: Size decreases by 1. Top datum is removed.
*/
void RPNCalc::dropCMD() {
    DS.pop();
}
/*
Name: dupCMD
Purpose: Duplicates the top datum on the datum stack.
Arguments: No arguments.
Returns: No returns.
Effects: Size increases by 1. Top datum is added to the stack.
*/
void RPNCalc::dupCMD() {
    DS.push(DS.top());
}
/*
Name: swapCMD
Purpose: Switches the position of the top two datums on the datum stack.
Arguments: No arguments.
Returns: No returns.
Effects: The top datum and the second datum positions are changed.
*/
void RPNCalc::swapCMD() {
    // taking top two off and reinserting them in opposite order
    Datum d1(DS.top());
    DS.pop();
    Datum d2(DS.top());
    DS.pop();
    DS.push(d1);
    DS.push(d2);
}
/*
Name: operCMD
Purpose: Computes operations +,-,*,/,% on two integers.
Arguments: std::string cmd which is the command the user inputs that has the
           operation to be executed.
Returns: No values returned.
Effects: Size decreases by 1. The top two integer data become one integer datum.
*/
void RPNCalc::operCMD(std::string cmd) {
    // getting integers to be operated on
    Datum d1(DS.top());
    dropCMD();
    Datum d2(DS.top());
    dropCMD();
    // conditionals to check which operation is to be performed
    if (cmd == "+") {
        Datum d3(d2.getInt() + d1.getInt());
        DS.push(d3);
    } else if (cmd == "-") {
        Datum d3(d2.getInt() - d1.getInt());
        DS.push(d3);
    } else if (cmd == "*") {
        Datum d3(d2.getInt() * d1.getInt());
        DS.push(d3);
    } else if (cmd == "/") {
        Datum d3(d2.getInt() / d1.getInt());
        DS.push(d3);
    } else if (cmd == "mod") {
        Datum d3(d2.getInt() % d1.getInt());
        DS.push(d3);
    }
}
/*
Name: ineqCMD
Purpose: Computes (in)equalities >,<,>=,<=,== on two integers.
Arguments: std::string cmd which is the command the user inputs that has the
           (in)equality to be executed.
Returns: No values returned.
Effects: Size decreases by 1. The top two integer data become one bool datum.
*/
void RPNCalc::ineqCMD(std::string cmd) {
    // getting the top two integers
    Datum d1(DS.top());
    dropCMD();
    Datum d2(DS.top());
    dropCMD();
    // conditions to determine the (in)equality to be used
    if (cmd == "<") {
        Datum d3(d2.getInt() < d1.getInt());
        DS.push(d3);
    } else if (cmd == ">") {
        Datum d3(d2.getInt() > d1.getInt());
        DS.push(d3);
    } else if (cmd == "<=") {
        Datum d3(d2.getInt() <= d1.getInt());
        DS.push(d3);
    } else if (cmd == ">=") {
        Datum d3(d2.getInt() >= d1.getInt());
        DS.push(d3);
    } else if (cmd == "==") {
        Datum d3(d2.getInt() == d1.getInt());
        DS.push(d3);
    }
}
/*
Name: rstringCMD
Purpose: Pushes an rstring datum onto the stack.
Arguments: std::string s which is the string that is to be pushed.
Returns: No returns.
Effects: Size increases by 1. New rstring datum on the top.
*/
void RPNCalc::rstringCMD(std::string s) {
    Datum d(s);
    DS.push(d);
}
/*
Name: execCMD
Purpose: Executes the contents inside of the top rstring.
Arguments: int Loopstart to determine where the execution process begins in
           the string to be exectuted, std::string str.
Returns: No returns.
Effects: Size may change depending on contents of rstring. Top value will
         change depending on the contents of the rstring.
*/
void RPNCalc::execCMD() {
    std::stringstream ss;
    if (not DS.top().isRString()) {
        std::cerr << "Error: cannot execute non rstring" << std::endl;
        dropCMD();
        return;
    }
    // gets the top rstring
    std::string s = DS.top().getRString();
    dropCMD();
    // reads in after the first brace to before the last brace
    s = s.substr(2, s.length() - 4);
    ss << s;
    // checks every input in the rstring and passes it through helper
    while (not ss.eof()) {
        runHelper(ss);
    }
}
/*
Name: fileCMD
Purpose: Reads the file in the top rstring datum and executes the content
         inside of the file.
Arguments: No arguments.
Returns: No returns.
Effects: Size may change depending on contents of rstring. Top value will
         change depending on the contents of the rstring.
*/
void RPNCalc::fileCMD() {
    std::ifstream ifs;
    std::stringstream ss;
    std::string cmd;
    if (not DS.top().isRString()) {
        std::cerr << "Error: file operand not rstring" << std::endl;
        dropCMD();
        return;
    }
    std::string s = DS.top().getRString();
    dropCMD();
    // get the file name from the rstring
    s = s.substr(2, s.length() - 4);
    ifs.open(s);
    // reading file into cmd and running it
    if (ifs.is_open()) {
        while(not ifs.eof()) {
            runHelper(ifs);
        }
    } else 
        std::cerr << "Unable to read " << s << std::endl;
    ifs.close();
}
/*
Name: ifCMD
Purpose: Acts like an if statement in a programming language. It gets a false
         case and a true case and uses a boolean datum to determine which case
         to execute.
Arguments: No arguments.
Returns: No returns.
Effects: Size may change depending on contents of rstring. Top value will
         change depending on the contents of the rstring. 
*/
void RPNCalc::ifCMD() {
    // getting the false/true cases and test condition
    Datum FalseCase(DS.top());
    dropCMD();
    Datum TrueCase(DS.top());
    dropCMD();
    Datum TestCon(DS.top());
    dropCMD();
    // checking for datum type errors that may occur
    if (not TestCon.isBool()) {
        std::cerr << "Error: expected boolean in if test" << std::endl;
        return;
    } else if ((not FalseCase.isRString()) or (not TrueCase.isRString())) {
        std::cerr << "Error: expected rstring in if branch" << std::endl;
        return;
    } 
    // uses the test condition to determine which case to execute
    if (TestCon.getBool()) {
        rstringCMD(TrueCase.getRString());
    } else if (TestCon.getBool() == false) {
        rstringCMD(FalseCase.getRString());
    }
    execCMD();
}
/*
Name: showStackCMD
Purpose: Prints out the entire stack.
Arguments: No arguments. 
Returns: No returns.
Effects: No values changed.
*/
void RPNCalc::showStackCMD() {
    // storing old data
    DatumStack temp = DS;
    int end = DS.size();
    // printing each top as it gets popped off to traverse the entire stack
    for (int i = 0; i < end; i++) {
        printCMD();
        DS.pop();
    }
    // ensures all invariants are recovered
    DS = temp;
}
/*
Name: parseRString
Purpose: Reads in an input stream and converts it to a string.
Arguments: std::istream &input which is the addres of the input stream passed.
Returns: std::string is returned which should be the same as '{' + &input.
Effects: No values changed.
*/
std::string RPNCalc::parseRString(std::istream &input) {
    std::stringstream ss;
    int exit = 1;
    std::string s;
    ss << '{';
    // exit if exit == 0 or end of file
    while ((not input.eof()) and (exit != 0)) {
        ss << s << " ";
        input >> s;
        // if it sees another {, increase exit by 1 (exit starts at 1)
        if (s == "}") {
            exit--;
        } else if (s == "{") {
            exit++;
        }
    }
    // closes the last bracket that wasn't read in
    ss << '}';
    return ss.str();
}
/*
Name: gotInt
Purpose: Checks if a string contains an integer and inserts that integer in
         the memory found at resultp.
Arguments: std::string s which is the string being checked that may contain
           an integer. int *resultp which is a pointer to the memory that will
           hold the integer in s if there are any.
Returns: Bool returned depending on if there is a integer in s or not.
Effects: *resultp value may change.
*/
bool RPNCalc::gotInt(std::string s, int *resultp) {
    // holds the first non-whitespace character after the integer
    char extra;
    return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}
/*
Name: gotOp
Purpose: Checks if a string contains an operator
Arguments: std::string cmd which is the string being checked that may contain
           an operator.
Returns: Bool returned depending on if the string has an operator or not.
Effects: No values changed.
*/
bool RPNCalc::gotOp(std::string cmd) {
    // checks if the command is an operator
    if ((cmd == "+") or (cmd == "-") or (cmd == "*") or (cmd == "/") or
       (cmd == "mod")) {
        return true;
    }
    return false;
}
/*
Name: gotEq
Purpose: Checks if a string contains an (in)equality.
Arguments: std::string cmd which is the string being checked that may contain
           an (in)equality.
Returns: Bool returned depending on if the string has an (in)equality or not.
Effects: No values changed.
*/
bool RPNCalc::gotEq(std::string cmd) {
    // checks if the command is an (in)equality
    if ((cmd == ">") or (cmd == "<") or (cmd == ">=") or (cmd == "<=") or
       (cmd == "==")) {
        return true;
    }
    return false;
}
/*
Name: runHelper
Purpose: Chooses which command to execute depending on the user input.
Arguments: std::string cmd which is the command inputted by the user.
Returns: No values returned.
Effects: All values my vary depending on user command.
*/
void RPNCalc::runHelper(std::istream &is) {
    // list of commands that may be executed depending on input
    int I;
    std::string cmd;
    while (is >> cmd) {
        try {
            if (cmd == "quit") {
                return;
            } else if (cmd == "{") {
                rstringCMD(parseRString(is));
            } else if (gotInt(cmd, &I)) {
                intCMD(I);
            } else if (cmd == "#t") {
                tBoolCMD();
            } else if (cmd == "#f") {
                fBoolCMD();
            } else if (gotOp(cmd)) {
                operCMD(cmd);
            } else if (gotEq(cmd)) {
                ineqCMD(cmd);
            } else if (cmd == "not") {
                notCMD();
            } else if (cmd == "print") {
                printCMD();
            } else if (cmd == "clear") {
                clearCMD();
            } else if (cmd == "drop") {
                dropCMD();
            } else if (cmd == "dup") {
                dupCMD();
            } else if (cmd == "swap") {
                swapCMD();
            } else if (cmd == "exec") {
                execCMD();
            } else if (cmd == "file") {
                fileCMD();
            } else if (cmd == "if") {
                ifCMD();
            } else if (cmd == "stack") {
                showStackCMD();
            } else
                std::cerr << cmd << ": unimplemented" << std::endl;
        } catch (const std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}