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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        stack.push(root);
        if(root == NULL) return preOrder;
        while(!stack.empty()){
            TreeNode* top = stack.top();
            stack.pop();
            preOrder.push_back(top -> val);
            if(top -> right != NULL)
                stack.push(top -> right);
            if(top -> left != NULL)
                stack.push(top -> left);
        }
        return preOrder;
    }
};