#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<bool> >visited;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    int n, m;

    bool isArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool dfs(vector<vector<char> > &board, int x, int y, int index, string word){

        if(board[x][y] != word[index])
            return false;

        if(index == word.size()-1){
            return true;
        }

        if(visited[x][y])
            return false;
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int temx = x + dx[i], temy = y + dy[i];
            if(isArea(temx,temy) && !visited[temx][temy] && board[temx][temy] == word[index+1]){
                if(dfs(board, temx, temy, index+1, word))
                    return true;
            }
        }
        visited[x][y] = false;
        return false;

    }
public:
    bool exist(vector<vector<char> > &board, string word) {

        n = board.size();
        if(n == 0 || word.size() == 0)
            return false;
        m = board[0].size();

        visited = vector<vector<bool>>(n,vector<bool>(m,false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};

int main(){

    vector<vector<char>> board = vector<vector<char>>{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "AF";
    cout << Solution().exist(board,word) << endl;

    return 0;
}