//
// Created by wokaka on 2018/8/11.
//
#include <bits/stdc++.h
using namespace std;

class Solution {
private:
    int n, m;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    vector<vector<bool> > visited;

    bool isArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        visited[x][y] = true;

        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(isArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                dfs(grid,newx,newy);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        visited.clear();
        n = grid.size();
        if(n == 0)
            return 0;
        m = grid[0].size();

        visited = vector<vector<bool> >(n, vector<bool>(m, false));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}