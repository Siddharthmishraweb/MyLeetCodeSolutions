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
    int levelOrderTraversal(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        int level = 0;
        while(!pendingNodes.empty()){
            level++;
            int size = pendingNodes.size();
            for(int i = 0 ; i < size; i++){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                if(front -> left) pendingNodes.push(front -> left);
                if(front -> right) pendingNodes.push(front -> right);
            }

        }
        return level;
    }
    int maxDepth(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};