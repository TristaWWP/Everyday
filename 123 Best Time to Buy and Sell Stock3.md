//有一组数组，里面的第i个元素就是第i天股票的价格，现在最多完成两次交易，求两次的最大利润

//Input: [3,3,5,0,0,3,1,4]
Output: 6
 //第5天买进，价格0，第6天卖出，价格3，利润为3；第二次第7天买进，价格1，第8天卖出，价格4，利润3，总利润6

**思路:这个题目好像不太懂它的意思，搞不懂**

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i:prices){   // Assume we only have 0 money at first
            release2 = max(release2, hold2+i);   // The maximum if we've just sold 2nd stock so far.
            hold2    = max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
};
```
