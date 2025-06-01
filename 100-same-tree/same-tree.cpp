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
        // iterative solution
        // 2 * i + 1
        vector<int> firstAns(1000, -1);
        vector<int> secondAns(1000, -1);

        queue<pair<TreeNode* , pair<TreeNode*, pair<int, int>>>>pendingNodes;
        pendingNodes.push({p, {q, {0, 0}}});
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
                auto front = pendingNodes.front();
                pendingNodes.pop();
                int i_index = front.second.second.first;
                int j_index = front.second.second.second;

                TreeNode* p_front = front.first;
                TreeNode* q_front = front.second.first;

                if((p_front == NULL && q_front != NULL) || (p_front != NULL && q_front == NULL)) return false;

         if(!p_front && !q_front) continue;

         if(p_front -> val != q_front -> val) return false;
                





                // if(p_front -> left && q_front -> left)
                 pendingNodes.push({p_front -> left, {q_front -> left, {2 * i_index + 1, ((2 * j_index) + 1)}}});

                // if(p_front -> right && q_front -> right) 
                pendingNodes.push({p_front -> right, {q_front -> right, {2 * i_index + 2, 2 * j_index + 2}}});
            }


        for(int i = 0 ; i < firstAns.size(); i++){
            cout << firstAns[i] <<" , "<< secondAns[i] <<endl;
            if(firstAns[i] != secondAns[i]) return false;
        }
        return true;
    }
};