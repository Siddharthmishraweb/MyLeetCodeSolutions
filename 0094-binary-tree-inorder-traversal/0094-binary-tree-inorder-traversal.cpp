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
        vector<int> output;
        stack<TreeNode*> stack;
        TreeNode* currNode = root;
        while(!stack.empty() || currNode){
            if(currNode != NULL){
                 stack.push(currNode);
                 currNode = currNode -> left;
            }
            else{
                 TreeNode* front = stack.top();
                 output.push_back(front -> val);
                 stack.pop();
                 currNode = front -> right;
            }
        }
        return output;
    }
};