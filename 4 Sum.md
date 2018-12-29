//给出一个整数数组和一个target，且数组中有四个数相加和为target，找到这样的不重复的所有集合

//nums = [1, 0, -1, -2, 2]   ，  target = 0，，res is[[-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2]]

**思路：设四个下标，第一个i，j=i+1；left = j + 1；right为最后一个**

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < int(nums.size()-3); ++i){
            for(int j = i + 1; j < int(nums.size()-2); ++j){
                if(j > i + 1 && nums[j] == nums[j-1])
                     continue;
                int left = j + 1, right = nums.size() - 1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left;
                        --right;
                    }
                    else if(sum < target)
                        ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>> (res.begin(), res.end());
    }
};
```
