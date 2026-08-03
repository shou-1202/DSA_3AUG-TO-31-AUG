class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int prev1 =0, prev2 = 0, prev3 =0, curr=-1e9;
        for(int i = n-1; i>=0; i--){
            int pick1 = stoneValue[i] - prev1;
            int pick2 = -1e9, pick3 = -1e9;
            if(i+1<stoneValue.size()){
                pick2 = stoneValue[i]+stoneValue[i+1] - prev2;
            }
            if(i+2<stoneValue.size()){
                pick3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - prev3;
            }

            curr = max(pick1, max(pick2, pick3));
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        string ans;
        int difference = prev1;
        if(difference>0){
            ans = "Alice";
        }
        else if(difference<0){
            ans = "Bob";
        }
        else{
            ans = "Tie";
        }
        return ans;
    }
};