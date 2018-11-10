//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m1;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            m1[s].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for(auto item : m1){
            ret.push_back(item.second);
        }

        return ret;
    }
};
int main(){
    string s[] = {"eat", "tea", "tan", "ate", "nat", "bat"};

    return 0;
}