/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
    bool isBST(TreeNode *root, TreeNode *maxNode, TreeNode *minNode) {
        if(!root) {
            return true;
        }
        if(maxNode && root->val >= maxNode->val || minNode && root->val <= minNode->val ) {
            return false;
        }
        return isBST(root->left, root, minNode) && isBST(root->right, maxNode, root);//左孩子比root小，右孩子比root大，所有对于左孩子，root是maxNode,对于右孩子，root是minNode
    }
};
