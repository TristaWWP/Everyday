//给出一个整数数组和一个target，在数组中找到三个数使他们的和最接近target，返回这个sum

//nums = [-1, 2, 1, -4]   ，  target = 1，，sum = 2，，-1+2+1=2

**思路：前面同上面三个题目，设第一个下标为i，i后面的一个下标为j，最后一个元素下标为right，一开始假设最接近target的是nums[0][1][2],此时最接近的这个数字closet跟target的差是diff，然后第一次循环，得到的sum，又得到一个新的差newdiff，比较两个diff，并更新diff跟closet**

```
class Solution {
public:
    int threeSumCloset(vector<int> &nums, int target) {
        int closet = nums[0] + nums[1] + nums[2];
        int diff = abs(closet - target);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < int(nums.size()-2); ++i){
            int j = i + 1, right = nums.size() - 1;
            while(j < right){
                int sum = nums[i] + nums[j] + nums[right];
                int newdiff = abs(sum - target);
                if(diff > newdiff){
                    diff = newdiff;
                    closet = sum;
                }
                if(sum > target) j++;
                    else right--;
            }
        }
        return closet;
    }
};
```
