//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        if(n <= 2) return ret;
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-1; i++){
            if(nums[i] > 0) break;
            int l = i+1, r = n-1;
            int sum = 0, target = 0 - nums[i];
            while(l < r){
                sum = nums[l] + nums[r];
                if(sum == target){
                    res.insert({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++, r--;
                }else if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }

        ret = vector<vector<int>>(res.begin(), res.end());
        return ret;
    }
};
int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ret = Solution().threeSum(nums);

    for(int i = 0; i < ret.size(); i++){
        for(int j = 0; j < 3; j++)
            cout << ret[i][j] << " " ;
        cout << endl;
    }
    return 0;
}