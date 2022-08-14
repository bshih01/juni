#include <unordered_map>
#include <typeinfo>
#include <iostream>
using namespace std;

int main() {
    unordered_map<int, int> m;
    string i = "ok";
    cout << "TYPE IS: " << typeid(m.begin()).name();
    return 0;
}