/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(root == null) return list;
        Queue<TreeNode> pendingNodes = new LinkedList<>();
        pendingNodes.add(root);
        while(pendingNodes.size() != 0){           
            int n = pendingNodes.size();
            List<Integer> internalList = new ArrayList<Integer>();
            for(int i = 0 ; i < n ; i++){
                 TreeNode front = pendingNodes.peek();
                 pendingNodes.remove();
                 internalList.add(front.val);
                if(front.left != null){
                    pendingNodes.add(front.left);
                }if(front.right != null){
                    pendingNodes.add(front.right);
                }
            }
            list.add(internalList);
        }
      return list;
    }
}