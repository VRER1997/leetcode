//
// Created by wokaka on 2018/8/12.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map<char,long long> m1;
        for(int i = 0; i < s.size(); i++){
            m1[s[i]]++;
        }

        priority_queue< pair<long long,char> >pq;
        for(map<char,long long>::iterator it = m1.begin(); it != m1.end(); it++){
            pq.push(make_pair((*it).second,(*it).first));
        }
        string ret = "";
        while(!pq.empty()){
            pair<long long, char> p = pq.top();
            ret.append(p.first, p.second);
            pq.pop();
        }
        return ret;
    }
};
int main(){
    string s = "Aabb";
    cout << Solution().frequencySort(s) << endl;
    return 0;
}