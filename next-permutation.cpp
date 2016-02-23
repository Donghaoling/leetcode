class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
    	int temp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = temp;
    }
    int findPivot(vector<int> &nums) {
    	int i = nums.size() - 1;
    	while (i > 0) {
    		if (nums[i - 1] < nums[i]) return i - 1;
    		else --i;
    	}
    	return -1; //为了处理3,2,1这样倒叙的情况
    }
    int findNextSuccessorIndex(vector<int> &nums, int pivot) {
    	if (pivot == -1) return -1; //为了处理3,2,1这样倒叙的情况
    	int i = nums.size() - 1;
    	while (i > pivot) {
    		if (nums[i] > nums[pivot]) {
    			return i;
    		}
    		else {
    			--i;
    		}
    	}
    }
    void reverse(vector<int> &nums, int pivot) {
    	int i = pivot + 1;
    	int j = nums.size() - 1;
    	while (i <= j) {
    		swap(nums, i, j);
    		i++;
    		j--;
    	}
    }
    void nextPermutation(vector<int>& nums) {
    	//using expaination on https://leetcode.com/discuss/72050/readable-code-without-confusing-i-j-and-with-explanation
    	int pivot = findPivot(nums);
    	int greater_index = findNextSuccessorIndex(nums, pivot);
    	if(pivot >= 0) swap(nums, pivot, greater_index);
    	reverse(nums, pivot);
    }
    
};
