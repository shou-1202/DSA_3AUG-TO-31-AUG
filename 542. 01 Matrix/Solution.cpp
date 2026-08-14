class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>dis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int step = q.front().second;
            dis[i][j] = step;
            q.pop();

            for(int k = 0; k<4; k++){
                int nrow = i+delrow[k];
                int ncol = j+delcol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step+1});
                }
            }
        }
        return dis;
    }
};