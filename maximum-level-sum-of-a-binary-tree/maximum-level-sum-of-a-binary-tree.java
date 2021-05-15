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
    public int maxLevelSum(TreeNode root) {
        int max = Integer.MIN_VALUE, ind = 0;
        Queue<TreeNode> q = new LinkedList<>();
        
        q.add(root);
        int lev = 1;
        while(!q.isEmpty()){
            int len = q.size();
            int val = 0;
            while(len>0){
                TreeNode cur = q.poll();
                val+=cur.val;
                if((cur.left)!=null)q.add(cur.left);
                if((cur.right)!=null) q.add(cur.right);
                len--;
            }
            
            if(val>max){
                max  = Math.max(max,val);
                ind  = lev;
            }
            
            lev++;
        }
        return ind;
    }
}