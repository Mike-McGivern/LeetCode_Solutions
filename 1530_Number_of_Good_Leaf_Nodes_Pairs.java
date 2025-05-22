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
    int ans;
    public int countPairs(TreeNode root, int distance) {
        ans = 0;
        dfs(root, distance);
        return ans;
    }
    
    private int[] dfs(TreeNode node, int distance) {
        int[] counts = new int[distance + 1];
        if (node == null) {
            return counts;
        }
        if (node.left == null && node.right == null) {
            counts[1] = 1;
            return counts;
        }
        int[] leftCounts = dfs(node.left, distance);
        int[] rightCounts = dfs(node.right, distance);
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance) {
                    ans += leftCounts[i] * rightCounts[j];
                }
            }
        }
        for (int i = 2; i <= distance; i++) {
            counts[i] = leftCounts[i - 1] + rightCounts[i - 1];
        }
        return counts;
    }
}
