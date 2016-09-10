class Solution {
public:
    void dfs(int i, int n, int remain, vector<vector<int>> &res, vector<int> cur) { //index从i开始，放remain个数到cur里
        if(remain == 0) {
            res.push_back(cur);
            return;
        }
        for(int j = i; j <= n; j++) { //index从i开始，依次放i到n的数
            cur.push_back(j);
            dfs(j + 1, n, remain - 1, res, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(1, n, k, res, cur);
        return res;
    }
};
