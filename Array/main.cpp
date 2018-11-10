#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 0, ret = n+1, sum = 0;
        while(j < n){
            sum += nums[j++];

            while(sum >= s){
                if(sum == s) ret = min(ret, j-i);
                sum -= nums[i++];

            }
        }
        return ret;
    }
};

int v(){
    int s = 7;
    vector<int> nums = vector<int>{2,3,1,2,4,3};

    cout << Solution().minSubArrayLen(s,nums);
    return 0;
}