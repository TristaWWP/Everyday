//题目要求：求最长递增子序列，注意：子序列和字串不同，子序列是不连续的
//题目描述：一串无序数组中，找到最长递增子序列的长度
input： 【10， 9， 2， 5， 3， 7， 101， 18】
output: 4    [2, 5, 7, 101]
//dp解法时间复杂度为O(n*n)




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int MyMax = 0;     
        for(int i = 0; i < nums.size(); ++i){//第一层外循环是dp[i]是每一个以nums[i]结尾的最长递增子序列的长度
            for(int j = 0; j < i; ++j){//第二层内循环是，对每个nums[i]，再从小于i的第一个开始查找，直到i
                if(nums[i]> nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);  //当某个数小于nums[i]，更新dp【i】              
                }         
            }
            MyMax = max(dp[i], MyMax);//最后整个dp数组的最大值，就是所求长度
        }
        return MyMax;
    }
};
