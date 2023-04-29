#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

inOrder =>   left root right
preOrder =>  root left right
postOrder => left right root
************************************************************/
#define pb push_back
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<BinaryTreeNode<int>*,int>> pendingNodes;
    pendingNodes.push({root, 1});
    while (!pendingNodes.empty()) {
       pair<BinaryTreeNode<int>*,int> top = pendingNodes.top();
       BinaryTreeNode<int>* node = top.first;
       int num = top.second;
       //preOrder
       if (num == 1) {
           preOrder.pb(node -> data);
           pendingNodes.pop();
           pendingNodes.push({node,num+1});
           if (node->left) {
             pendingNodes.push({node -> left, 1});
           }
       }
       //inOrder
       if (num == 2) {
           inOrder.pb(node -> data);
           pendingNodes.pop();
           pendingNodes.push({node,num+1});
           if (node->right) {
             pendingNodes.push({node -> right, 1});
           }
       }
       //postOrder
       if (num == 3) {
         postOrder.pb(node -> data);
         pendingNodes.pop();
       }
    }
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);
    return ans;
}
