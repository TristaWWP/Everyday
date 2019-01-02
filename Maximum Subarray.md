//给出一个整数数组，找到一个连续的子数组，这个连续的子数组的和最大,输出这个和

//Input [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//Output [4, -1, 2, 1], sum = 6.

**思路：普通方法：从数组的第一个数开始计算，依次求和，如果小于0，则从那个数重新开始计算，继续依次相加；分治法：将大问题变成小问题，设一个dp的vector，dp存每次求的值，如果大于0，就加上数组的下一个数，如果小于0，该dp位置设为0，即重新开始，将每次的dp跟max比较，并更新max**


```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int Mymax = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            Mymax = max(Mymax, dp[i]);
        }
        return Mymax;
    }
};
//another version
int maxSubArray(vector<int>& nums) {
        int preSum, totalSum;
        preSum = totalSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (preSum < 0) preSum = nums[i];
            else preSum += nums[i];
            if (preSum > totalSum) totalSum = preSum;
        }
        return totalSum;
    }
```
