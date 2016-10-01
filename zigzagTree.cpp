public class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) 
    {
        List<List<Integer>> sol = new ArrayList<>();
        travel(root, sol, 0);
        return sol;
    }
    
    private void travel(TreeNode curr, List<List<Integer>> sol, int level)
    {
        if(curr == null) return;
        
        if(sol.size() <= level)
        {
            List<Integer> newLevel = new LinkedList<>();
            sol.add(newLevel);
        }
        
        List<Integer> collection  = sol.get(level);
        if(level % 2 == 0) collection.add(curr.val);
        else collection.add(0, curr.val);
        
        travel(curr.left, sol, level + 1);
        travel(curr.right, sol, level + 1);
    }
}

class Solution {
public:
    map<TreeNode*, int> depthMap;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        depthMap[root] = 1;
        //calculate depth of a node
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
                depthMap[node->left] = depthMap[node]+1;
            }
            if(node->right) {
                q.push(node->right);
                depthMap[node->right] = depthMap[node]+1;
            }
        }
        q.push(root);
        bool useStack = false;
        depth = 1;
        stack<int> st;
        queue<int> que;
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
            if(depth != depthMap[node]) {
                vector<int> vec;
                if(useStack) {
                    while(!st.empty()) {
                        vec.push_back(st.top());
                        st.pop();
                    }
                }
                else {
                    while(!que.empty()) {
                        vec.push_back(que.front());
                        que.pop();
                    }
                }
                res.push_back(vec);
                useStack = !useStack;
                depth++;
            }
            if(useStack) {
                st.push(node->val);
            }
            else {
                que.push(node->val);
            }
            
        }
        vector<int> vec;
    	while (!st.empty()) {
    		vec.push_back(st.top());
    		st.pop();
    	}
    	while (!que.empty()) {
    		vec.push_back(que.front());
    		que.pop();
    	}
    	res.push_back(vec);
        return res;
    }
};
