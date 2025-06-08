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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, map<int, int>& inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inOrderMapIndex = inMap[root -> val];
        int numsLeft = inOrderMapIndex - inStart;

        root -> left = _buildTree(preorder, inorder, preStart + 1, numsLeft + preStart, inStart, inOrderMapIndex - 1, inMap);

                root -> right = _buildTree(preorder, inorder, preStart + 1 + numsLeft, preEnd, inOrderMapIndex + 1, inEnd, inMap);

                return root;



    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderMap;
        for(int i = 0 ; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        TreeNode* root = _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorderMap);
        return root;
    }
};