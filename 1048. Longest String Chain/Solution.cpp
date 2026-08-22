class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, string& b){
            return a.size()<b.size();
        });

        int maxi = 1;
        vector<int>dp(n, 1);
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                string b = words[i];
                string a = words[prev];
                int k = 0, j =0, count = 0;
                while(k>=0 && k<a.length() && j>=0 && j<b.length()){
                    if(count>1)break;
                    if(a[k] != b[j]){
                        count++;
                        j++;
                        continue;
                    }
                    k++;j++;
                }
                if(count>1)continue;
                if(words[i].length()-words[prev].length()==1 && dp[i]<1+dp[prev]){
                    dp[i] = 1+dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};