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
    vector<int> rightSideView(TreeNode* root) {
        int cur = 0;
        vector<TreeNode*> vec;
        vector<int> out;
        vector<vector<int>> result;
        if(root == NULL) {
            return out;
        }
        vec.push_back(root);
        while(cur < vec.size()) {
            int end = vec.size();
            vector<int> temp;
            while(cur < end) {
                temp.push_back(vec[cur]->val);
                TreeNode *node = vec[cur];
                if(node->left) {
                    vec.push_back(node->left);
                }
                if(node->right) {
                    vec.push_back(node->right);
                }
                cur ++;
            }
            result.push_back(temp);
        }
        for(int i = 0;i < result.size();i ++) {
            out.push_back(result[i][result[i].size()-1]);
        }
        return out;
    }
};
