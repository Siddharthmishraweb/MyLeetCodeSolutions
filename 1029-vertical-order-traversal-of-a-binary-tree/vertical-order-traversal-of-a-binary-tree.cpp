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
    vector<pair<int, pair<int, int>>> pairVector;
    void horizontalDepth(TreeNode* root, int depth, int hd){
        if(!root) return ;
        pairVector.push_back({ hd , { depth, root -> val }});
        if(root -> left) horizontalDepth(root -> left, depth + 1, hd - 1);
        if(root -> right) horizontalDepth(root -> right, depth + 1, hd + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> finalAns;
        horizontalDepth(root, 0, 0);
        map<int, vector<int>> mapi;
        sort(pairVector.begin(), pairVector.end());
        for(auto p: pairVector){
            cout << p.first <<" , "<<p.second.first <<" , "<< p.second.second<<endl;
            mapi[p.first].push_back(p.second.second);
        }
        for(auto p: mapi){
            vector<int> ans;
            finalAns.push_back(p.second);
        }
        return finalAns;
    }
};