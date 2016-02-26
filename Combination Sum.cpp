class Solution {
public:
    void backtrack(int i, vector<vector<int>> &res, vector<int> &v, vector<int> &nums, int remain) {
        if(remain == 0) {
            res.push_back(v);
            return;
        }
        if(remain < 0) {  //相当于剪枝。
            return;
        }
        for(int j = i; j < nums.size(); ++j) {
            v.push_back(nums[j]);
            backtrack(j, res, v, nums, remain-nums[j]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(0, res, v, candidates, target);
        return res;
    }
};
