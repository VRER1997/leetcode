//
// Created by wokaka on 2018/8/14.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map1;
        for(int i = 0; i < nums.size(); i++){
            map1[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(map<int,int>::iterator it = map1.begin(); it != map1.end(); it++){
            pq.push(make_pair((*it).second,(*it).first));
        }
        vector<int> ret ;
        for(int i = 0; i < k; i++){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};