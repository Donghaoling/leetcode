class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &cache) {
        if(cache[i][j] != 0) {
            return cache[i][j];
        }
        int maxLen = 1;
        for(auto it = dirs.begin(); it != dirs.end(); it++) {
            vector<int> dir = *it;
            int x = i + dir[0];
            int y = j + dir[1];
            if(x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(x, y, m, n, matrix, cache);
            maxLen = max(len, maxLen);
        }
        cache[i][j] = maxLen;
        return maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m,vector<int>(n, 0));
        int res = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int len = dfs(i, j, m, n, matrix, cache);
                if(len > res) res = len;
            }
        }
        return res; 
    }
    
};
