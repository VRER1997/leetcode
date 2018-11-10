//
// Created by wokaka on 2018/8/13.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> memo;
    int tryFind(int n){
        if(n == 0)
            return 0;
        int ret = n+1;
        if(memo[n] != -1)
            return memo[n];
        for(int i = 1; i*i <= n; i++)
            ret = min(ret, tryFind(n-i*i)+1);
        memo[n] = ret;
        return ret;
    }
    int numSquares(int n) {
        memo = vector<int>(n+1, -1);
        return tryFind(n);
    }
};
int main(){
    cout << Solution().numSquares(12) << endl;
    return 0;
}