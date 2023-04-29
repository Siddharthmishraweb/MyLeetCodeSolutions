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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> Nodes;
        queue<pair<TreeNode*,pair<int,int>>> pendingNodes;
        pendingNodes.push({root,{0,0}});
        while(!pendingNodes.empty()){
            auto front = pendingNodes.front();
            pendingNodes.pop();
            TreeNode* node = front.first;
            int x = front.second.first;
            int y = front.second.second;
            Nodes[x][y].insert(node->val);
            if(node -> left){
                pendingNodes.push({node->left,{x-1,y+1}});
            }
            if(node -> right){
                pendingNodes.push({node->right,{x+1,y+1}});
            }
        }
       vector<vector<int>> ans;
       for(auto x:Nodes){
           vector<int> mm;
           for(auto y:x.second){
               mm.insert(mm.end(), y.second.begin(),y.second.end());
           }
           ans.push_back(mm);
       }
         return ans;
    }
};