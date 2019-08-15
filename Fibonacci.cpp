//递归使得调用过程栈溢出，效率低，所以减少重复计算
//优化算法，从下往上计算，根据f(0),f(1)得到f(2),再有f(1)和f(2)得到f(3)

#include<iostream>

using namespace std;

long long Fibonacci(unsigned int n)
{
    /* if(n <= 0)//效率最差的递归解法
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
     return Fibonacci(n -1) + Fibonacci(n - 2); */
     
     //正确性判断
     if(n == 0 || n == 1)
     {
         return n;
     }
     //优化算法，从下往上计算，根据f(0),f(1)得到f(2),再有f(1)和f(2)得到f(3)
    long long nums1 = 0;
    long long nums2 = 1;
    long long res = 0;
    for(unsigned int i = 2 ; i <= n; ++i)
    {
        res = nums1 + nums2;
        nums1 = nums2;
        nums2 = res;
    }
    return res;
}

int main()
{
    long long result;
    result = Fibonacci(40);
    cout << result; 
    return 0;
}

//一种创建数组保存的方法,将已经得到的数列中间项保存在一个数组里

/* int *array = new int[n+1];
array[0] = 0;
array[0] = 1; 
for(int i = 2; i <= n; ++i)
{
    array[i] = array[i-1]+ array[i-2];
}
int result = array[n];
delete []array;

*/
