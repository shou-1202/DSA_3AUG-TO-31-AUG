/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start>end)return NULL;
        int idx = 0, maxi = INT_MIN;
        for(int i = start; i<=end; i++){
            if(maxi<nums[i]){
                idx = i;
                maxi = nums[i];
            }
        }

        TreeNode* root = new TreeNode(nums[idx]);

        root->left = helper(nums, start, idx-1);
        root->right = helper(nums, idx+1, end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
};