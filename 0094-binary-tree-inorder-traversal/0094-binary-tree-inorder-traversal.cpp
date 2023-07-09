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
    vector<int> sol;
    void helper(TreeNode* root){
        if(root == NULL)
            return ;
        if(root -> left) helper(root -> left);
        sol.push_back(root -> val);
        if(root -> right) helper(root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return sol;
    }
};