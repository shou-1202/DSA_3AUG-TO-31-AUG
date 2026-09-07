class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.length();
        
        // dp[i] will store the number of distinct subsequences of length i
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: 1 subsequence for the empty string
        
        // Array to store the last seen index of each character
        vector<int> last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            // Initially, we double the subsequences from the previous step
            dp[i + 1] = (dp[i] * 2) % mod;
            
            // If we have seen this character before, subtract the duplicates
            int charIndex = s[i] - 'a';
            if (last[charIndex] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[charIndex]] + mod) % mod;
            }
            
            // Update the last seen index of the current character
            last[charIndex] = i;
        }
        
        // Subtract 1 at the end to exclude the empty subsequence
        return (dp[n] - 1 + mod) % mod;
    }
};