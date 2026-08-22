class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1), temp(n, 0);
        int maxi = 1, lastidx = 0;
        for(int i = 1; i<n; i++){
            temp[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev]){
                    dp[i] = dp[prev]+1;
                    temp[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastidx]);
        while(temp[lastidx]!=lastidx){
            lastidx = temp[lastidx];
            ans.push_back(nums[lastidx]);
        }
        return ans;
    }
};