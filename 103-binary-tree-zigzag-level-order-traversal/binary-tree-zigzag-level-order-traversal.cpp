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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int index = 0;
        queue<TreeNode* >pendingNodes;
        pendingNodes.push(root);
        vector<vector<int>> finalAns;
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            index++;
            vector<int> ans;
            for(int i = 0; i < size ; i++){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                ans.push_back(front -> val);
                if(front -> left) pendingNodes.push(front -> left);
                if(front -> right) pendingNodes.push(front -> right); 
            }
            if(index % 2 == 0)
               reverse(ans.begin(), ans.end());
            finalAns.push_back(ans);
 
        }
        return finalAns;
    }
};