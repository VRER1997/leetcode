//
// Created by wokaka on 2018/8/11.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isAlphaNum(char &ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++)
            s[i] = tolower(s[i]);
        int i = 0, j = n-1;
        while(i < j){
            if(!isAlphaNum(s[i]))i++;
            else if(!isAlphaNum(s[j])) j--;
            else if(s[i] != s[j]) return false;
            else i++, j--;
        }
        return true;
    }
};
int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}