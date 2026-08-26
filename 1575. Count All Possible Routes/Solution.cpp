class Solution {
public:
    int mod = 1e9 + 7;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>>dp(n, vector<int>(fuel+1, 0));
        for(int i = 0; i<=fuel; i++){
            dp[finish][i] = 1;
        }
        for(int i = 0; i<=fuel; i++){
            for(int j = 0; j<n;j++){
                for(int k = 0; k<n; k++){
                    if(j==k)continue;
                    int cost = abs(locations[j] - locations[k]);
                    if(i>=cost){
                        dp[j][i] = (dp[j][i] + dp[k][i-cost])%mod;
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};