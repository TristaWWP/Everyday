/* 这是Leetcode的第一个题目，同时也让我看到时间复杂度的重要性
本文给出两个解法，看下优秀的解法大大提高了时间复杂度
题目描述：给一个数组nums=[2,7,11,15],target=9;求出两个数相加和为9的下标
方法一：普通方法，循环数组，知道找到另一个数=target-循环数
方法二：unordered_map的用法，里面是无序的无重复的元素，底层是hash表，map底层是红黑树
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
vector<int> twoSum1(vector<int> &nums, int target)//普通方法，遍历数组
{
    vector<int> res(2,0);
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[j] == target - nums[i])
            {
                res[0] = i;
                res[1] = j;
            }
        }
    }
    return res;
}
vector<int> twoSum2(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); ++i)//建立一个数值-下标的无序map
    {
        m[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); ++i)
    {
        int t = target - nums[i];
        if(m.count(t) && m[t] != i)//count判断key值出现的次数，因为map中不存在重复元素，所以返回1
        {
            res.push_back(i);
            res.push_back(m[t]);
            break;
        }
    }
    return res;
}
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    int target = 9;
    vector<int> res;
   // res = twoSum1(v,target);
    res = twoSum2(v,target);
    for(auto c : res)
    {
        cout << c;
    }
    cout<< endl;
    return 0;
}
