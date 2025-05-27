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
    vector<vector<int>> finalAns;
    vector<int> ans;
    void helper(TreeNode* root){
        if(!root) return ;
 
        ans.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL){
            finalAns.push_back(ans);
        }

        if(root -> left )helper(root -> left);
        if(root -> right )helper(root -> right);
        ans.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> finalPath;
        helper(root);
        for(auto f: finalAns){
            int i = 0;
            string str="";
            for(auto item: f){
               i++;
               string toAppend = i != f.size() ? "->" : "";
               str += to_string(item)  + toAppend;
               cout << str ;
            }
            finalPath.push_back(str);
            cout << endl;
        }
     return finalPath;
    }
};