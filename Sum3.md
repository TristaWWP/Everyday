//给出一个整数数组，且数组中有三个数相加和为0，找到这样的不重复的所有集合

//nums = [-1, 0, 1, 2, -1, -4] . res is[[-1, 0, 1], [-1, -1, 2]]

**思路：为避免重复使用set数据结构，设第一个下标为i，i后面的一个下标为j，最后一个元素下标为right，看三个数加起来是否为0，**
**如果等于0，继续寻找下一组，即j++，right--；；如果sum<0,则需要sum变大，即只要j++；；如果sum>0，则需要sum变小，即right--；；**
**然后继续进行最外面for（i）的循环**

```
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        set<vector<int>> res;//创建一个vector类型的set，其中vector又是int类型的，该set集合每个元素的值唯一
        sort(nums.begin(), nums.end());//sort（参数1，参数2，参数3）1是首地址，2尾地址，3缺省即升序，3为cmp即降序
        for(int i = 0; i < int(nums.size()-2); i++){
            int j = i + 1, right = nums.size()-1;
                if(j > i + 1 && nums[j] == nums[j - 1])
                   continue;
                while(j < right){
                    int sum = nums[i] + nums[j] + nums[right];
                    if(sum == 0){
                        vector<int> out{nums[i], nums[j], nums[right]};
                        res.insert(out);
                        j++;
                        right--;
                    }
                    else if(sum < 0) j++;
                    else right--;
                }
        }
        return vector<vector<int>> (res.begin(), res.end());
    }
};
```
