class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return;
        if(grid[i][j] == 0 || vis[i][j])return;
        vis[i][j] = 1;

        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i, j-1);
        dfs(grid, vis, i, j+1);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i =0; i<m; i++){
            if(grid[0][i]==1){
                dfs(grid, vis, 0, i);
            }
            if(grid[n-1][i] == 1){
                dfs(grid, vis, n-1, i);
            }
        }
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(grid, vis, i, 0);
            }
            if(grid[i][m-1] == 1){
                dfs(grid, vis, i, m-1);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};