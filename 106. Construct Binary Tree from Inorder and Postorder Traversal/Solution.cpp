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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end, int& j){
        if(start>end)return NULL;
        TreeNode* root = new TreeNode(postorder[j]);
        j--;

        int idx=0;
        for(int i = start; i<=end; i++){
            if(inorder[i]==root->val){
                idx= i;
                break;
            }
        }
        root->right = helper(inorder, postorder, idx+1, end, j);
        root->left = helper(inorder, postorder, start, idx-1, j);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int j = n-1;
        return helper(inorder, postorder, 0, n-1, j);
    }
};