/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root -> val == p -> val || root -> val == q-> val)
            return root ;
        TreeNode* leftOne = lowestCommonAncestor(root -> left, p, q) ;
        
        TreeNode* rightOne = lowestCommonAncestor(root -> right,  p,  q) ;
        if(leftOne == NULL)
            return rightOne;
        if(rightOne == NULL)
            return leftOne;
        if(leftOne != NULL && rightOne != NULL)
            return root;
        return root;
    }
};