//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
//输入: ["2", "1", "+", "3", "*"]
//输出: 9
//解释: ((2 + 1) * 3) = 9
class Solution {
public:
    int toInt(string s){
        int start = 0;
        if(s[0] == '-')
            start = 1;
        int sum = 0;
        for(int i = start; i < s.size(); i++)
            sum = sum*10 + (s[i]-'0');
        return start ? (0-sum) : sum;
    }
    bool isOp(string s){
        return s == "+" || s == "-" ||s == "*" || s == "/";
    }

    int OP(int x, int y, string s){
        if(s == "+") return x+y;
        if(s == "-") return x-y;
        if(s == "*") return x*y;
        if(s == "/") return x/y;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        for(int i = 0; i < tokens.size(); i++){
            string s = tokens[i];
            if(!isOp(s)){
                s1.push(toInt(s));
            }else{
                int x = s1.top();s1.pop();
                int y = s1.top();s1.pop();
                s1.push(OP(y,x,s));
            }
        }

        return s1.top();
    }
};
int main(){
    vector<string> ret = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << Solution().evalRPN(ret) << endl;
    return 0;
}