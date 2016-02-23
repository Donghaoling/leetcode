class Solution {
public:
    void backtrack(int i, vector<int> &nums, vector<vector<int>> &res, vector<int> v) {
        if(i > nums.size()) {
            res.push_back(v);
            return;
        }
        for(int j = 0; j < 2; ++j) {
            if(j == 0) {
                backtrack(i+1, nums, res, v);
            }
            else {
                v.push_back(nums[i-1]);
                backtrack(i+1, nums, res, v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(), nums.end());
        backtrack(1, nums, res, v);
        return res;
    }
};
