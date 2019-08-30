//字符串相加“123”+“123”=“246”
//思路：不难，一位一位的相加，算和及进位，根据进位情况看是否需要补一个高位
//注意：string字符转化为int整数相加，-‘0’，同样int整数，转为string+‘0’
//类似的还有：二进制相加，链表相加，字符串加1

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1 = "123";
    string str2 = "123";
    string res = "";
    int m = str1.size(), n = str2.size(), i = m - 1, j = n - 1, carry = 0;
    while(i >= 0 || j >= 0)
    {
        int a = i >= 0 ? str1[i--] - '0' : 0;//减去0，是减去0的ACSCII值，得到一个可以相加的整数，相当于类型转换
        int b = j >= 0 ? str2[j--] - '0' : 0;
        int sum = a + b + carry;
        res.insert(res.begin(), sum % 10 + '0');//从开始位置插入字符
        carry = sum / 10;
    }
    res = carry ? "1" + res : res;
    cout << res;
    return 0;
}
