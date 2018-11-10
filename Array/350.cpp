//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mymap;
        for(int i = 0; i < nums1.size(); i++)
            mymap[nums1[i]]++;

        vector<int> ret;
        for(int i = 0; i < nums2.size(); i++){
            if(mymap[nums2[i]]){
                ret.push_back(nums2[i]);
                mymap[nums2[i]]--;
            }
        }

        return ret;
    }
};
int main(){
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> ret = Solution().intersect(nums1,nums2);
    for(int i = 0; i < ret.size(); i++){
        cout << ret[i] << " " ;
    }
    cout << endl;
    return 0;
}