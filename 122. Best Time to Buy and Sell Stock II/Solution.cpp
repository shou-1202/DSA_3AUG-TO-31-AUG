class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr0 = 0, curr1 = 0, next0 = 0, next1 = 0;
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                long profit = -1e9;
                if(buy){
                   profit = max(-prices[i]+next0, next1);
                   curr1 = profit;
                }
                else{
                   profit = max(prices[i]+next1, next0);
                   curr0 = profit;
                }
            }
            next0 = curr0;
            next1 = curr1;
        }
        return next1;
    }
};