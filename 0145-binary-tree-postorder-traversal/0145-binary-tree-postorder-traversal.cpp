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
  left right node
 */
class Solution {
public:
    vector<int> sol;
    void helper(TreeNode* root){
        if(root == NULL)return;
        helper(root -> left);
        helper(root -> right);
        sol.push_back(root ->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return sol;
    }
};