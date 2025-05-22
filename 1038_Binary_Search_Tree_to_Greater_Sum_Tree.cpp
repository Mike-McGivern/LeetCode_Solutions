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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInOrder(root, sum);
        return root;
    }

private:
    void reverseInOrder(TreeNode* node, int& sum) {
        if (node == nullptr) {
            return;
        }

        // Traverse the right subtree first
        reverseInOrder(node->right, sum);

        // Update the sum and the node's value
        sum += node->val;
        node->val = sum;

        // Traverse the left subtree
        reverseInOrder(node->left, sum);
    }
};
