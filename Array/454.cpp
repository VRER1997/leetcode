//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> m1;
        for(int i = 0; i < A.size(); i++){
            for(int j =0; j < B.size(); j++){
                m1[A[i]+B[j]]++;
            }
        }

        int cnt = 0;
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                if(m1[0-(C[i]+D[j])])
                    cnt += m1[0-(C[i]+D[j])];
            }
        }

        return cnt;
    }
};
int main(){
    vector<int> A = { 1, 2 };
    vector<int> B = { -2,-1 };
    vector<int> C = { -1, 2 };
    vector<int> D = { 0, 2 };
    int ret = Solution().fourSumCount(A,B,C,D);
    cout << ret << endl;
    return 0;
}