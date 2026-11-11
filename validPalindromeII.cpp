/**
 Reminder: Use Recursion
 */
 #include <iostream>
using namespace std;
class Solution {
public:
    pair<int,int> g = {0,0};
    pair<int,int> validPal2(string s,int p1 , int p2) {
        while( p1 < p2) {
            if (s[p1] == s[p2]) {
                p1 ++;
                p2 --;
            } else {
                return {p1,p2};
            }
        }
        return g;
    }
    bool validPalindrome(string s) {
        int p1 = 0;
        int p2 = s.size() - 1;
        pair<int,int> gg = validPal2(s,p1,p2);
        if (gg == g) {
            return true;
        } else if (validPal2(s,gg.first,gg.second -1) == g) {
            return true;
        } else if (validPal2(s,gg.first+1,gg.second) == g) {
            return true;
        } else {
            return false;
        }
    }
   
};



// Second Solution : Two much space needed
// class Solution {
// public:
//     pair<int,int> g = {0,0};
//     pair<int,int> validPal2(string s,int p1 , int p2) {
//         if (p1 >= p2) {
//             return g;
//         }
//         if (s[p1] == s[p2]) {
//             return validPal2(s,p1+1,p2-1);
//         } else {
//             return {p1,p2};
//         }
//     }
//     bool validPalindrome(string s) {
//         int p1 = 0;
//         int p2 = s.size() - 1;
//         pair<int,int> gg = validPal2(s,p1,p2);
//         if (gg == g) {
//             return true;
//         } else if (validPal2(s,gg.first,gg.second -1) == g) {
//             return true;
//         } else if (validPal2(s,gg.first+1,gg.second) == g) {
//             return true;
//         } else {
//             return false;
//         }
//     }
   
// };