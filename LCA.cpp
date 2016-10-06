class Solution {
public:
    bool dfs(TreeNode *root, TreeNode *resRoot, vector<TreeNode*> &res) {
    	if (!root) {
    		return false;
    	}
    	res.push_back(root);
    	if(root == resRoot ) {
    	    return true;
    	}
    	if(dfs(root->left, resRoot, res)) {
    	    return true;
    	}
    	if(dfs(root->right, resRoot, res)){
    	    return true;
    	}
    	res.pop_back();
    	return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> res1;
    	dfs(root, p, res1);
    	vector<TreeNode*> res2;
    	dfs(root, q, res2);
    	auto it1 = res1.begin();
    	auto it2 = res2.begin();
    	TreeNode* ret = root;
    	while (it1 != res1.end() && it2 != res2.end() && (*it1) == (*it2)) {
    		ret = (*it1);
    		it1++;
    		it2++;
    	}
    	return ret;
    }
};
