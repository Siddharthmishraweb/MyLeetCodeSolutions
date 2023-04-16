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
        vector<int> inOrder;
        TreeNode* node = root;
        stack<TreeNode*> stack;
        while(true){
            if(node != NULL){
                stack.push(node);
                node = node -> left;
            }else{
                if(stack.empty()) break;
                node = stack.top();
                inOrder.push_back(node ->val);
                stack.pop();
                node = node  -> right;
            }
        }
        return inOrder;
    }
};