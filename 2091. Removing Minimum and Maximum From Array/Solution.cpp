class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN, k, j;
        for(int i= 0;i<n; i++){
            if(mini>nums[i]){
                mini = nums[i];
                j=i;
            }
            if(maxi<nums[i]){
                maxi = nums[i];
                k = i;
            }
        }
        int left = min(j, k);
        int right = max(j, k);

        int case1 = right+1;
        int case2 = n-left;
        int case3 = (left+1) + (n-right);

        return min(case1, min(case2, case3));

    }
};