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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& j){
        if(start > end)return NULL;

        TreeNode* root = new TreeNode(preorder[j]);
        j++;

        int idx = 0;
        for(int i = start; i<=end; i++){
            if(inorder[i]==root->val){
                idx = i;
                break;
            }
        }
        root->left = helper(preorder, inorder, start, idx-1, j);
        root->right = helper(preorder, inorder, idx+1, end, j);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int j = 0;
        return helper(preorder, inorder, 0, n-1, j);
    }
};