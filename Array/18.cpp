//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if(n <= 3) return ret;
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                int l = j+1, r = n-1;
                int sum = 0, t = target - nums[i] - nums[j];
                while(l < r){
                    sum = nums[l] + nums[r];
                    if(sum == t){
                        res.insert({nums[i],nums[j], nums[l],nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++, r--;
                    }else if(sum < t){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }

        ret = vector<vector<int>>(res.begin(), res.end());
        return ret;
    }
};
int main(){
    int target = 0;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret = Solution().fourSum(nums, target);

    for(int i = 0; i < ret.size(); i++){
        for(int j = 0; j < 4; j++)
            cout << ret[i][j] << " " ;
        cout << endl;
    }
    return 0;
}