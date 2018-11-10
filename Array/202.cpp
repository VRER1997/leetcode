//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toVector(int n){
        vector<int> ret;
        while(n){
            ret.push_back(n%10);
            n /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        vector<int> ret = toVector(n);
        map<int, int> myMap;
        myMap[n] = 1;
        while(!(ret.size() == 1 && ret[0] == 1)){
            int sum = 0;
            for(int i = 0; i < ret.size(); i++){
                sum += ret[i]*ret[i];
            }
            if(myMap[sum]) return false;
            else myMap[sum] = 1;
            ret = toVector(sum);
        }
        return true;
    }
};
int main(){
    cout << Solution().isHappy(1) << endl;
    return 0;
}