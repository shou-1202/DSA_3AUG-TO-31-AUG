class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>after(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy <=1; buy++){
                for(int count = 1; count<=k; count++){
                    long profit = -1e9, take = -1e9, notTake = -1e9;
                    if(buy){
                       take = -prices[i] + after[0][count];
                       notTake = after[1][count];
                       profit = max(take, notTake);
                    }
                    else{
                       take = prices[i]+after[1][count-1];
                       notTake = after[0][count];
                       profit = max(take, notTake);
                    }
                    curr[buy][count] = profit;
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};