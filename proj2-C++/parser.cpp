#include <sstream>
#include <iostream>

std::string parseRString(std::istream &input) {
    std::stringstream ss;
    int exit = 1;
    std::string s;
    ss << "{";
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
    ss << '}';
    return ss.str();
}