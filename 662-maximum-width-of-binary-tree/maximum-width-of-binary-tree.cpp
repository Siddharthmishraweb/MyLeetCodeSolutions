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
    long long levelOrderTraversal(TreeNode* root){
        queue<pair<TreeNode*, int>> pendingNodes;
        pendingNodes.push({root, 0});
        long long maxWidth = INT_MIN;
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            long long firstOne = -1;
            int lastOne = -1;
            for(int i = 0 ; i < size; i++){
                TreeNode* front = pendingNodes.front().first;
                long long level =  pendingNodes.front().second;
                if(i == 0) firstOne = level;
                pendingNodes.pop();
                if(front -> left) pendingNodes.push({front -> left, 2*level + 1});
                if(front -> right) pendingNodes.push({front -> right, 2 * level + 2});
                // last index
                if(i == size - 1){
                  maxWidth = max((level - firstOne) + 1, maxWidth);
                }
            }
        }
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};