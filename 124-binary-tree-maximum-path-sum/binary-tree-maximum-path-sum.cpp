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
    int maxi = -121;
    int helper(TreeNode* root) {
        if(root == NULL) return 0;

        int leftAns = max(0, helper(root -> left));
        int rightAns = max(0, helper(root -> right));

        maxi = max(maxi, leftAns + rightAns + root -> val);

        return max(leftAns , rightAns) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }
};