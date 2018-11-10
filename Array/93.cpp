//
// Created by wokaka on 2018/8/29.
//

#include <bits/stdc++.h>
using namespace std;
//输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"]
class Solution {
public:
    vector<string> ret;
    void dfs(string s, string ip, int k, int num, int pnum){
        if(k == s.size() || pnum == 3){
            ret.push_back(ip);
        }
        if(num > 255 || num < 0 || pnum > 3)
            return;
        for(int i = k; i < s.size(); i++){
            ip += s[i];
            dfs(s,ip+'.',k+1,num*10+s[i]-'0',pnum+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,"",0,0,0);
        return ret;
    }
};

int main(){
    vector<string> ret =  Solution().restoreIpAddresses("25525511135");
    for(string t : ret){
        cout << t << endl;
    }
    return 0;
}