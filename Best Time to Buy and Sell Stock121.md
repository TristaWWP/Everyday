//有一组数组，里面的第i个元素就是第i天股票的价格，现在只能完成一次交易，即先买后卖，求最大利润，就是找第一个数跟第二个数，保证第二个减第一个差值最大

//Input [7, 1, 5, 3, 6, 4]
//Output = 5, 第二天买进，价格1，第五天卖出，价格6，利润为5

**思路：Kadane's Algorithm，寻找最大子数列，用maxCur记录当前的最大值，用maxSoFar记录目前所发现的最大值，不断更新两个数，其中maxCur是相邻两数之差+自身，因为两个任意位置数的差值，可以由他们之间连续的每两个数的差值相加求得**

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};
```
//当然也可以循环找到最小值，然后求每个数的差值，直至最大差值
