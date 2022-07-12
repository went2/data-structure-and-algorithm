//
//  check-balanced-parenthese.cpp
//  
//
//  Created by WenTommy on 2022/7/12.
//

#include <stdio.h>
#include <stack>

bool isParenBalanced(char* str);
bool isOpeningParen(char c);
bool isClosingParen(char c);

using namespace std;

int main() {
    char* str;
    str = (char*)"{([])}";
    if (isParenBalanced(str)) {
        printf("balanced.\n");
    } else {
        printf("NOT balanced.\n");
    }
    return 0;
}

bool isParenBalanced(char* str) {
    stack<char> S;
    
    for(int i=0; i<strlen(str); i++) {
        if (isOpeningParen(str[i])) {
            S.push(str[i]);
        } else if (isClosingParen(str[i])) {
            if (S.empty()) {
                return false;
            } else {
                S.pop();
            }
        }
    }
    return S.empty();
}

bool isOpeningParen(char c) {
    if (c == '(' || c == '{' || c == '[') {
        return true;
    }
    return false;
}

bool isClosingParen(char c) {
    if (c == ')' || c == '}' || c == ']') {
        return true;
    }
    return false;
}

