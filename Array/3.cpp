//
// Created by wokaka on 2018/8/11.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 1;
        int l = 0, r = 1, ret = 0;
        set<char> myset;
        myset.insert(s[0]);
        while(r < n){
            if(myset.find(s[r]) == myset.end()){
                myset.insert(s[r++]);
                ret = max(ret, r-l);
            }
            else{
                while(s[l] != s[r]){
                    myset.erase(s[l]);
                    l++;
                }
                myset.erase(s[l]);
                l++;
            }
        }

        return ret;
    }
};
int main(){
    string s = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}