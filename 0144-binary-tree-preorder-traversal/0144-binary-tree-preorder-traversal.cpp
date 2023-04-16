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
  root left right
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        stack<TreeNode*>stack;
        TreeNode* node = root;
        while(true){
            if(node !=NULL){
                preOrder.push_back(node -> val);
                stack.push(node);
                node = node -> left;
            }else{
                if(stack.empty()) break;
                node = stack.top();
                stack.pop();
                node = node -> right;
            }
        }
        return preOrder;
    }
};