//
// Created by wokaka on 2018/8/12.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        map<char, char> m1;
        for(int i = 0; i < n; i++){
            if(m1.find(s[i]) != m1.end()){
                if(m1[s[i]] != t[i])
                    return false;
            }else{
                m1[s[i]] = t[i];
            }
        }
        map<char, char> m2;
        for(int i = 0; i < n; i++){
            if(m2.find(t[i]) != m2.end()){
                if(m2[t[i]] != s[i])
                    return false;
            }else{
                m2[t[i]] = s[i];
            }
        }

        return true;
    }
};
int main(){
    string s = "foo", t = "bar";
    int ret = Solution().isIsomorphic(s,t);
    cout << ret << endl;
    return 0;
}