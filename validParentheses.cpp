#include <iostream>
#include <map>
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> l;
        map <char,char> br = {{')','('},{']','['}, {'}','{'}};
        for (const char& d : s) {
            if (d == '{' || d == '('|| d == '[') {
                l.push(d);
            } else {
                if (l.empty()==true){
                    return false;
                }
                if (l.top() == br [d]) {
                    l.pop();
                } else {
                    return false;
                }
            }
        }
        if (l.empty()== true) {
            return true;
        } else {
            return false;
        }
    }
};