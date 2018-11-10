//
// Created by wokaka on 2018/8/12.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> split(string str){
        vector<string> ret;
        int i = 0, n = str.size();
        int cnt = 0;
        string s = "";
        while(i < n){
            if(str[i] == ' '){
                ret.push_back(s);
                s = "";
            }else{
                s = s+str[i];
            }
            i++;
        }
        ret.push_back(s);
        return ret;

    }
    bool wordPattern(string pattern, string str) {
        int n = pattern.size();
        vector<string> strs = split(str);
        int m = strs.size();
        if(n != m)
            return false;
        map<char, string> myMap;
        for(int i = 0; i < n; i++){
            if(myMap.find(pattern[i]) != myMap.end()){
                if(myMap[pattern[i]] != strs[i])
                    return false;
            }else{
                myMap[pattern[i]] = strs[i];
            }
        }

        map<string, char> myMap2;
        for(int i = 0; i < n; i++){
            if(myMap2.find(strs[i]) != myMap2.end()){
                if(myMap2[strs[i]] != pattern[i])
                    return false;
            }else{
                myMap2[strs[i]] = pattern[i];
            }
        }
        return true;
    }
};

int main(){

    string pattern = "abba", str = "dog dog dog dog";
//    vector<string> strs = Solution().split(str);
    cout << Solution().wordPattern(pattern, str) << endl;
    return 0;
}