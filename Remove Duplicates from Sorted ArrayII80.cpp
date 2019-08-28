/* 题目描述：有序数组去重，允许重复次数2
思路：同样采用快慢指针的方法，多增加一个count记录还有几次重复，初始值1
1 一开始快指针指向1，慢指针指向0
2 如果快慢指针对应值相等即重复，并且count为0，那么快指针走一步
3 否则：如果快慢指针对应值相等，即重复一次，那么count减1，否则，不重复，count恢复为1
此时，慢指针走一步，把快指针的值赋给慢指针，然后快指针走一步
返回慢指针+1；
 */
#include<iostream>
#include<vector>

 using namespace std;

 class Solution
 {
     public:
     int removeDuplicates2(int nums[],int n)
     {
         int fast = 1, slow = 0;
         int count = 1;
         if(n <= 2)
         {
            return n;
         }           
        
        while(fast < n)
        {
            if(nums[fast] == nums[slow] && count == 0)
                ++fast;
            else
            {
                if(nums[fast] == nums[slow])
                    --count;
                else 
                    count = 1;
                nums[++slow] = nums[fast++];
            }
        }
        return slow+1;
     }
 };

 int main()
 {
     Solution s;
     int v[]={1,1,1,2,2,3};
    // int data;
    // vector<int> v= {1,1,1,2,2,3};
   /*  while(cin >> data)
    {
        v.push_back(data);
    } */
     int length = s.removeDuplicates2(v,6);
     cout << length;
     return 0;
 }
