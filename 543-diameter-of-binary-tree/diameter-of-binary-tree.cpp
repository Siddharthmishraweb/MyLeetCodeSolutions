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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+ max(height(root -> left), height(root -> right));
    }
    int maxi = INT_MIN;
    int diameter(TreeNode* root){
        int leftHeight = 0;
        int rightHeight = 0;
        if(root -> left){
            leftHeight = height(root -> left);
        }
        if(root -> right){
            rightHeight = height(root -> right);
        }
        // cout << "leftHeight: "<<leftHeight<< " ,rightHeight: "<<rightHeight<<endl;
        maxi = max(maxi, leftHeight + rightHeight);
        if(root -> left) diameter(root -> left);
        if(root -> right) diameter(root -> right);
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return diameter(root);
    }
};