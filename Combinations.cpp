class Solution {
public:
    void backtrack(int i, vector<vector<int>> &res, vector<int> v, int cnt, int n, int k) {
        if(i > n || cnt >= k) {
            if(cnt >= k) res.push_back(v);
            return;
        }
        for(int j = 0; j < 2; ++j) {
            if(j == 0) {
                backtrack(i+1, res, v, cnt, n, k);
            }
            else {
                cnt ++;
                if(cnt <= k) {
                    v.push_back(i);
                    backtrack(i+1, res, v, cnt, n, k);
                    v.pop_back();
                    cnt --;
                }
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(1, res, v, 0, n, k);
        return res;
    }
};
