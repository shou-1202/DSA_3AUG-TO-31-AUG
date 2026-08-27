class Solution {
public:
    int longestIdealString(string s, int k) {
        // dp[i] stores the max length of an ideal string ending with the i-th alphabet letter
        vector<int> dp(26, 0); 
        int max_len = 0;
        
        for (char c : s) {
            int curr = c - 'a';
            int longest_prev = 0;
            
            // Check all valid previous characters within range 'k'
            for (int prev = 0; prev < 26; prev++) {
                if (abs(curr - prev) <= k) {
                    longest_prev = max(longest_prev, dp[prev]);
                }
            }
            
            // The new longest string ending in 'curr'
            dp[curr] = longest_prev + 1; 
            max_len = max(max_len, dp[curr]);
        }
        
        return max_len;
    }
};