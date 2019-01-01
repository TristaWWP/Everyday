//给出一个有序数组以及一个target，如果这个target存在，返回他的索引，如果不存在，返回可以插入的位置索引，以便有序

//Input ：[1, 3, 5, 6], target = 5; Output = 2

//Input : [1, 3, 5, 6], target = 2; Output = 1

**思路：不能一个个比较，复杂度太高，可以用二分查找法，分别设左右两个界限，可以返回left，也可以返回right， mid = left + （right - left）/2**


```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       // if (nums.back() < target) return nums.size();
       int left = 0, right = nums.size() -1;
       // while (left < right) {
        //    int mid = left + (right - left) / 2;
        //    if (nums[mid] == target) return mid;
        //    else if (nums[mid] > target) right = mid;
        //    else left = mid + 1;
       // }
       //   return right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
```
