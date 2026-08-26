class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        
        if(i>=dungeon.size() || j>=dungeon[0].size())return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int health=1;
        if(dungeon[i][j]<0){
            health += abs(dungeon[i][j]);
        }
        if(i==dungeon.size()-1 && j == dungeon[0].size()-1)return health;
        int right = helper(i, j+1, dungeon, dp);
        int down = helper(i+1, j, dungeon, dp);

        int health_need =  min(right, down);

        int current_need = max(1, health_need-dungeon[i][j]);

        return dp[i][j] = current_need;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n =dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(0, 0, dungeon, dp);
    }
};