class Solution {
//How do we find these two elements? For example, we have the following tree that is printed as in order traversal:6, 3, 4, 5, 2
//We compare each node with its next one and we can find out that 6 is the first element to swap because 6 > 3 and 2 is the second element to swap because 2 < 5.
//Really, what we are comparing is the current node and its previous node in the "in order traversal".
public:
    TreeNode *preNode = new TreeNode(-100000);
    TreeNode *firstNode;
    TreeNode *secondNode;
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;
    }
    void traverse(TreeNode *root) {
        if(!root) {
            return;
        }
        traverse(root->left);
        if(firstNode == NULL && preNode->val >= root->val) {
            firstNode = preNode;
        }
        if(firstNode != NULL && preNode->val >= root->val) {
            secondNode = root;
            //return;
        }
        preNode = root;
        traverse(root->right);
    }
};
