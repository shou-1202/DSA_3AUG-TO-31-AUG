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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int r = INT_MIN;
        while(q.size()!=1){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                q.push(NULL);
                ans.push_back(r);
                r = INT_MIN;
                continue;
            }
            r = max(curr->val, r);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        ans.push_back(r);
        return ans;
    }
};