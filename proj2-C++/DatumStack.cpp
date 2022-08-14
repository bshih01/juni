/*
 *  DatumStack.cpp
 *  Brandon Shih
 *  3/8/22
 *
 *  COMP 15 Proj2 RPNCalc
 *
 *  This class uses the c++ list and delegates the list functions into
 *  the datum stack public member functions. By doing so, the list object
 *  can manage and change the status of the datum stack. 
 */

#include "DatumStack.h"
#include "Datum.h"
#include <stdexcept>

/*
Name: DatumStack
Purpose: Default constructor for the datum stack. Initializes the datum stack.
Arguments: No arguments.
Returns: No returns.
Effects: DatumStack is initialized.
*/
DatumStack::DatumStack() {}

/*
Name: DatumStack
Purpose: Constructor for the datum stack. Initializes the datum stack with
         an array of data.
Arguments: Datum data[] which is the array of data being pushed into the
           datum stack. int arrSize which is the size of the array being
           added.
Returns: No returns.
Effects: DatumStack is initialized. Size is arrSize.
*/
DatumStack::DatumStack(Datum data[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        datumStack.push_front(data[i]);
    }
}
/*
Name: isEmpty
Purpose: Checks if the datum stack is empty.
Arguments: No arguments.
Returns: Bool is returned depending on if it is empty.
Effects: No values changed.
*/
bool DatumStack::isEmpty() {
    return datumStack.empty();
}
/*
Name: clear
Purpose: Removes all data from the data stack.
Arguments: No arguments.
Returns: No returns.
Effects: Size is set to 0. All data is removed.
*/
void DatumStack::clear() {
    int end = datumStack.size();
    for (int i = 0; i < end; i++) {
        datumStack.pop_front();
    }
}
/*
Name: size
Purpose: Checks the size of the datum stack.
Arguments: No arguments.
Returns: int for the size of the datum stack is returned.
Effects: No values changed.
*/
int DatumStack::size() {
    return datumStack.size();
}
/*
Name: top
Purpose: Checks the top datum on the datum stack.
Arguments: No arguments.
Returns: Datum on the top is returned.
Effects: No values changed.
*/
Datum DatumStack::top() {
    if (isEmpty()) {
        throw std::runtime_error("empty_stack");
    }
    return datumStack.front();
}
/*
Name: pop
Purpose: Removes the top datum from the stack.
Arguments: No arguments.
Returns: No values returned. 
Effects: Size decreases by 1. Top datum is removed.
*/
void DatumStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("empty_stack");
    }
    datumStack.pop_front();
}
/*
Name: push
Purpose: Adds a datum to the top of the stack.
Arguments: Datum d which is the datum to be added.
Returns: No returns.
Effects: Size increases by 1. Top datum is now d.
*/
void DatumStack::push(Datum d) {
    datumStack.push_front(d);
}