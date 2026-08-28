class Solution {
    // Helper to generate all subset sums for a portion of the array
    void generateSums(int i, int end, vector<int>& nums, int currentSum, vector<int>& sums) {
        if (i == end) {
            sums.push_back(currentSum);
            return;
        }
        // Branch 1: Pick the current number
        generateSums(i + 1, end, nums, currentSum + nums[i], sums);
        
        // Branch 2: Don't pick the current number
        generateSums(i + 1, end, nums, currentSum, sums);
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> leftSums, rightSums;
        
        // 1 & 2: Generate subset sums for the left and right halves
        generateSums(0, n / 2, nums, 0, leftSums);
        generateSums(n / 2, n, nums, 0, rightSums);
        
        // 3: Sort one of the halves to enable binary search
        sort(rightSums.begin(), rightSums.end());
        
        int minDiff = 2e9; // Start with a very large number
        
        // 4: Loop through the left half and binary search the right half
        for (int x : leftSums) {
            int target = goal - x;
            
            // Find the first element in rightSums that is >= target
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            
            // Check the element we found (if it exists)
            if (it != rightSums.end()) {
                minDiff = min(minDiff, abs(goal - (x + *it)));
            }
            
            // Check the element right before it (if it exists)
            // It might be smaller than target, but closer in absolute value!
            if (it != rightSums.begin()) {
                auto prev_it = prev(it);
                minDiff = min(minDiff, abs(goal - (x + *prev_it)));
            }
        }
        
        return minDiff;
    }
};
 
