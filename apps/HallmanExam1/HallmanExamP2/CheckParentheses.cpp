//File: CheckParentheses.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <iostream>
#include <stack>
#include <string>

bool areParenthesesBalanced(const std::string& input) {
    std::stack<char> s;

    for (char ch : input) {
        if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (areParenthesesBalanced(input)) {
        std::cout << "The string contains matching parentheses." << std::endl;
    }
    else {
        std::cout << "The string does not contain matching parentheses." << std::endl;
    }

    return 0;
}