//给出一个整数数组和一个target，返回相加为target的两数的下标

//nums = [2, 7, 11, 15]     ,  target = 9 return [0,1]

**思路：设一个下标为i，则另一个下标j = target - i**

```
class Solution{
public:
    vector<int> twoSum(vector<int>&nums, int target){
        vector<int> news(2, 0);  //建立一个长度为2的new，每个元素是0
        for(int i = 0; i < nums.capacity(); i++){
            for(int j = i + 1; j < nums.capacity(); j++){
                if(nums[j] == target - nums[i]){
                    news[0] = i;
                    news[1] = j;
                }
            }
        }
        return news;
    }
};
```
