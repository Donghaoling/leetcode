class Solution {
public:
    void helper(vector<vector<int>> &m, vector<int> &x, int t) {
        if(t >= x.size()) {
            m.push_back(x);
        }
        for(int i = t; i < x.size(); ++i) {
            swap(x[t], x[i]);
            if(t < x.size()) {
                helper(m, x, t+1);
            }
            swap(x[t] ,x[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> m;
        helper(m, nums, 0);
        return m;
    }
};
