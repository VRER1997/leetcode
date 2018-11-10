//
// Created by wokaka on 2018/8/29.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> board = {
            {},{},
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'},
    };
    vector<string> ret;
    void dfs(string digits, string word, int k){
        if(k == digits.size()){
            ret.push_back(word);
        }
        int curNum = digits[k] - '0';
        for(int i = 0; i < board[curNum].size(); i++){
            dfs(digits, word+board[curNum][i], k+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return ret;
        dfs(digits,"",0);
        return ret;
    }
};
