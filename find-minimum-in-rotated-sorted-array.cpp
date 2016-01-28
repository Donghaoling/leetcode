class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = r / 2;
        while(l < r - 1){
            mid = (l + r) / 2;
            if(nums[mid] > nums[nums.size() - 1]){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        return min(nums[l],nums[r]);
    }
};
