class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(1001, 1));
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j<i; j++){
                int diff = nums[i]-nums[j] + 500;

                dp[i][diff] = 1+dp[j][diff];
                max_len = max(max_len, dp[i][diff]);
            }
        }
        return max_len;
    }
};