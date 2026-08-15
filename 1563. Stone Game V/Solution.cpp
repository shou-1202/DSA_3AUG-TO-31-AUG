class Solution {
public:
    int helper(vector<int>& stoneValue, int low, int high,vector<vector<int>>& dp,vector<int>& prefixSum){
        if(low == high)return 0;\
        if(dp[low][high]!=-1)return dp[low][high];
        int n = stoneValue.size();
        int ans = -1e9;
        for(int i = low; i<high; i++){
            int left = 0, right = 0;
            if(low!=0){
                left = prefixSum[i] - prefixSum[low-1];
            }
            else{
                left = prefixSum[i];
            }
            right = prefixSum[high] - prefixSum[i];
            int pick = -1e9, notPick=-1e9;
            if(left==right){
                pick = left+helper(stoneValue, low, i, dp,prefixSum);
                notPick = right+helper(stoneValue, i+1, high, dp, prefixSum);
                ans = max(ans, max(pick, notPick));
            }
            else if(left>right){
                pick = right+helper(stoneValue, i+1, high, dp, prefixSum);
                ans = max(ans, pick);
            }
            else{
                notPick = left+helper(stoneValue, low, i, dp,prefixSum);
                ans = max(ans, notPick);
            }
        }
        return dp[low][high] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        vector<int>prefixSum(n, 0);
        prefixSum[0] = stoneValue[0];
        for(int i = 1; i<n; i++){
            prefixSum[i] = prefixSum[i-1]+stoneValue[i];
        }
        return helper(stoneValue, 0, n-1, dp,prefixSum);
    }
};