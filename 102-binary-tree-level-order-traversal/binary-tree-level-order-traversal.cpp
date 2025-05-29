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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        vector<vector<int>> finalAns;
        while(!pendingNodes.empty()){
           int n = pendingNodes.size();
           vector<int> ans;
           for(int i = 0 ; i < n; i++){
            TreeNode* front = pendingNodes.front();
            cout<<front->val;
            ans.push_back(front -> val);
            pendingNodes.pop();
            if(front -> left) pendingNodes.push(front -> left);
            if(front -> right) pendingNodes.push(front -> right);
           }
           finalAns.push_back(ans);
        }
        return finalAns;
    }
};