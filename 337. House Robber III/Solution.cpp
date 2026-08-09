class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
    
private:
    // Returns a pair: {max_if_robbed, max_if_not_robbed}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        
        // Post-order traversal: process children first
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        
        // Option 1: Rob this node 
        // (Must add the "not robbed" values of children)
        int rob_this = node->val + left.second + right.second;
        
        // Option 2: Do NOT rob this node 
        // (Can take the max of robbing or not robbing children)
        int not_rob_this = max(left.first, left.second) + max(right.first, right.second);
        
        return {rob_this, not_rob_this};
    }
};