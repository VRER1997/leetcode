//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> myMap;
        for(int i = 0; i < s.size(); i++){
            myMap[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++){
            if(myMap[t[i]]){
                myMap[t[i]]--;
            }else{
                return false;
            }
        }

        for(int i = 0; i < 26; i++){
            if(myMap[i+'a'])
                return false;
        }

        return true;
    }
};
int main(){
    string s = "anagram", t = "nagaram";
    cout << Solution().isAnagram(s,t) << endl;
    return 0;
}