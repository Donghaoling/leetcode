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

class Solution {
public:
    void backtrack2(int i, set<vector<int>> &res, vector<int> &v, vector<int> &nums, int remain) {
    	if (remain == 0) {
    		res.insert(v);
    		return;
    	}
    	if (remain < 0) return;
    	for (int j = i; j < nums.size(); ++j) {
    		v.push_back(nums[j]);
    		backtrack2(j + 1, res, v, nums, remain - nums[j]);
    		v.pop_back();
    	}
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	vector<int> v;
    	set<vector<int>> res;
    	vector<vector<int>> ret_res;
    	sort(candidates.begin(), candidates.end());
    	backtrack2(0, res, v, candidates, target);
    	for (auto it = res.begin(); it != res.end(); ++it) {
    		ret_res.push_back(*it);
    	}
    	return ret_res;
    }
};

class Solution {
public:
    void backtrack(int i, vector<vector<int>> &res, vector<int> &v, int remain, int cnt, int k) {
        if(remain == 0 && cnt == k) {
            res.push_back(v);
            return;
        }
        if(remain < 0 || cnt > k) return;
        for(int j = i; j < 10; j++) {
            v.push_back(j);
            cnt++;
            backtrack(j+1, res, v, remain-j, cnt, k);
            cnt--;
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(1, res, v, n, 0, k);
        return res;
    }
};
