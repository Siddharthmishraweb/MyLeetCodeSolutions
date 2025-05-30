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
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        vector<vector<int>> finalAns;
        int index = 0;
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            vector<int> ans;
            index++;

            for(int i = 0 ; i < size; i++){
                TreeNode* front = pendingNodes.front();
                ans.push_back(front -> val);
                pendingNodes.pop();
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