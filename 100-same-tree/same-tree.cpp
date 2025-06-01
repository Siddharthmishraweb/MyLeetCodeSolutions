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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode* , TreeNode*>>pendingNodes;
        pendingNodes.push({p, q});
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
                auto front = pendingNodes.front();
                pendingNodes.pop();


                TreeNode* p_front = front.first;
                TreeNode* q_front = front.second;

                if((p_front == NULL && q_front != NULL) || (p_front != NULL && q_front == NULL)) return false;

         if(!p_front && !q_front) continue;

         if(p_front -> val != q_front -> val) return false;
                





                // if(p_front -> left && q_front -> left)
                 pendingNodes.push({p_front -> left, q_front -> left});

                // if(p_front -> right && q_front -> right) 
                pendingNodes.push({p_front -> right, q_front -> right});
            }


        return true;
    }
};