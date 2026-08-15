class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())return;
        if(board[i][j] == 'X')return;
        if(vis[i][j])return;
        vis[i][j] = 1;

        dfs(i-1, j, board, vis);
        dfs(i+1, j, board, vis);
        dfs(i, j-1, board, vis);
        dfs(i, j+1, board, vis);
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i<m; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, vis);
            }
            if(board[n-1][i] == 'O'){
                dfs(n-1, i, board, vis);
            }
        }
        for(int i = 0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }
            if(board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]!=1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};