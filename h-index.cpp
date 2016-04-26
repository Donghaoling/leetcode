class Solution {
public:
    int hIndex(vector<int>& citations) {
        //首先桶排序，再从后往前统计
        int n = citations.size();
        vector<int> buckets(n+1, 0);
        for(int i = 0; i < n; ++i) {
            if(citations[i] >= n) {
                buckets[n]++;
            } else {
                buckets[citations[i]]++;
            }
        }
        int count = 0;
        for(int i = n; i >= 0; i--) {
            count += buckets[i];
            if(count >= i) {
                return i;
            }
        }
        return 0;
    }
};
