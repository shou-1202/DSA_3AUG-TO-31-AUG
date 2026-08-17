class Solution {
public:
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        long profit = 0;
        int take = -1e9, notTake = -1e9;
        if(buy){
            profit = max(-prices[i]+helper(i+1, 0, prices, dp), helper(i+1, 1, prices, dp));
        }
        else{
            take = prices[i] + helper(i+2, 1, prices, dp);
            notTake = helper(i+1, 0, prices, dp);
            profit = max(take, notTake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int after0 = 0, after1 = 0, curr0 = 0, curr1 = 0;
        int next2 = 0;
        for(int i = n-1; i>=0; i--){
            for(int buy= 0; buy<=1; buy++){
                long profit = 0;
                int take = -1e9, notTake = -1e9;
                if(buy){
                  profit = max(-prices[i]+after0, after1);
                  curr1 = profit;
                }
                else{
                    take = prices[i];
                    if(i<n-1)take += next2;
                    notTake = after0;
                    profit = max(take, notTake);
                    curr0 = profit;
                }
            }
            next2 = after1;
            after0 = curr0;
            after1 = curr1;

        }
        return after1;
    }
};