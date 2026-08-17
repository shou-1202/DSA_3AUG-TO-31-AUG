class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // We need n + 1 size for both dimensions. 
        // Initializing with 0 automatically handles the base cases (when i == n).
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Build bottom-up, starting from the end of the array
        for(int i = n - 1; i >= 0; i--) {
            
            // p represents the index of the previously picked element.
            // It can range from i - 1 down to -1 (meaning nothing picked yet).
            for(int p = i - 1; p >= -1; p--) {
                
                // Option 1: Don't pick nums[i]
                // Move to i + 1, previously picked element is still p
                // (We do p + 1 to handle the -1 shift)
                int notPick = dp[i + 1][p + 1];
                
                // Option 2: Pick nums[i]
                int pick = 0;
                if(p == -1 || nums[i] > nums[p]) {
                    // Move to i + 1, the newly picked element is now i
                    // (We do i + 1 to handle the shift)
                    pick = 1 + dp[i + 1][i + 1];
                }
                
                // Store the max of both choices
                dp[i][p + 1] = max(pick, notPick);
            }
        }

        // The answer is the state where we start at index 0, 
        // and nothing has been picked yet (p = -1).
        // Shift -1 by +1 to get index 0.
        return dp[0][0]; 
    }
};