//
// Created by wokaka on 2018/8/13.
//

#include <bits/stdc++.h>
using namespace std;
  // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };

class NestedIterator {
public:
    stack<NestedInteger> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() -1; i >= 0; i--)
            s.push(nestedList[i]);
    }

    int next() {
        NestedInteger n = s.top(); s.pop();
        return n.getInteger();
    }

    bool hasNext() {
        while (!s.empty()){
            NestedInteger n = s.top();
            if(n.isInteger()) return true;
            s.pop();
            vector<NestedInteger> v = n.getList();
            for(int i = v.size()-1; i >= 0; i--){
                s.push(v[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */