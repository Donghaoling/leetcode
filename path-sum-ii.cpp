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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        path(root, sum, temp, result);
        return result;
    }
    bool path(TreeNode *node, int sum, vector<int> cur, vector<vector<int>>& res) {
        if(!node) return false;
        cur.push_back(node->val);
        if(!node->left && !node->right) {
            if(sum == node->val) { 
                res.push_back(cur);
                return true;
            }
            else {
                return false;
            }
        }
        bool ret = false;
        if(path(node->left, sum - node->val, cur, res)) ret = true;
        if(path(node->right, sum - node->val, cur, res)) ret = true;
        cur.pop_back();
        return ret;
    }
};
