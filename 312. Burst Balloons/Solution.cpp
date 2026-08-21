class Solution {
public:
    int helper(int left, int right, vector<vector<int>>& dp, vector<int>& nums){
        if(left>right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];

        int max_coins = 0;
        for(int i = left; i<=right; i++){
            int current = nums[i]*nums[left-1]*nums[right+1];
            int fut = helper(left, i-1, dp, nums)+helper(i+1, right, dp, nums);

            max_coins = max(max_coins, current+fut);
        }

        return max_coins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return helper(1, n, dp, nums);
    }
};