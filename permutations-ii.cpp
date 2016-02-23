class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //大致思路是：比如要排序{1,2,3}，首先插入一个数{1}，然后再插入2，复制{1}为两份，一个在1左边插入，一个在1右边插入。{2,1},{1,2}，然后插入3,3可以插在三个位置，分别是{3,1,2},{1,3,2},{1,2,3}。
        vector<vector<int>> res;
        vector<int> init = {nums[0]};
        res.push_back(init);
        for(int i = 1; i < nums.size(); ++i) {//对于每个要插入的数字
            vector<vector<int>> new_ans; //存储当前数字的插入结果
            for(auto it = res.begin(); it != res.end(); ++it) { //对于存储插入结果里的每个vector，都进行插入
                vector<int> temp = *it;
                for(auto it1 = temp.begin(); ; ++it1) { //对vector进行插入
                    it1 = temp.insert(it1, nums[i]);
                    new_ans.push_back(temp);
                    it1 = temp.erase(it1);
                    if(it1 == temp.end()) break;
                    //以上四句和不重复的permutation一样。
                    if(*it1 == nums[i]) break; //当要插入的数和当前的数相等的时候，只要插入一次就可以了。比如3,3,0，要插入3，首先是330序列，插入一次3，变成3330 就可以了，因为3303在后面303插入一次可以得到。
                }
            }
            res = new_ans;
        }
        return res;
    }
};
