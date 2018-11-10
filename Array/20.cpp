//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isLeft(char ch){
        return ch == '(' || ch == '{' || ch == '[';
    }
    bool match(char t, char s){
        if(t == '(' && s == ')') return true;
        if(t == '{' && s == '}') return true;
        if(t == '[' && s == ']') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> s1;
        for(int i = 0; i < s.size(); i++){
            if(isLeft(s[i]))
                s1.push(s[i]);
            else{
                if(s1.empty()) return false;
                char t = s1.top();
                s1.pop();

                if(!match(t,s[i]))
                    return false;
            }
        }
        if(!s1.empty()) return false;
        return true;
    }
};
int main(){
    string s = "()[]{}";
    cout << Solution().isValid(s) << endl;
    return 0;
}