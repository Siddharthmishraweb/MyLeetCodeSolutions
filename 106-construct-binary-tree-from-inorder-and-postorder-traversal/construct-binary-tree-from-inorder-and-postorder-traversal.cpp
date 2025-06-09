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
    TreeNode* _buildTree(vector<int>& postOrder, int inStart, int inEnd, int postStart, int postEnd, map<int, int>& inOrderMap){
        if(inStart > inEnd || postStart > postEnd) return NULL;
        TreeNode* root = new TreeNode(postOrder[postEnd]);
        int indexToMove = inOrderMap[root -> val]; // index of root
        int lefttree = indexToMove - inStart;
        root -> left = _buildTree( postOrder, inStart, indexToMove - 1, postStart,  postStart + lefttree - 1, inOrderMap);
        root -> right = _buildTree( postOrder, indexToMove + 1, inEnd, postStart + lefttree, postEnd - 1, inOrderMap);
     return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inOrderMap;
        for(int i = 0 ; i < inorder.size(); i++) inOrderMap[inorder[i]] = i;
        return _buildTree( postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inOrderMap);
    }
};