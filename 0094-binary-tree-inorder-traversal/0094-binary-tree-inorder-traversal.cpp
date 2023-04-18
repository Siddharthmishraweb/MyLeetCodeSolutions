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
    vector<int> inorderTraversal(TreeNode* root) {
        //Morris Inorder Traversal => using threaded binary tree
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left == NULL){
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }else{
                TreeNode* prev = curr -> left;
                // find the right most guy
                while(prev -> right != NULL && prev -> right != curr){
                    prev = prev -> right;
                }
                // if threaded connection doesnt already exist
                if(prev -> right == NULL){
                    prev -> right = curr;
                    curr = curr -> left;
                }//if threded connection already exist means we travessed the left part then remove connection
                else{
                    inorder.push_back(curr -> val);
                    prev -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return inorder;
    }
};