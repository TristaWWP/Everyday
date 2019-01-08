//给出两个二进制字符串，返回他们的和（也是一个二进制字符串）
  
// a = "11" , b = "1" , sum = "100"
**思路：新建一个string，用两个指针分别指向两个输入string的末尾，每次取出一个字符转为数字，若无法取出字符则按照0处理，定义carry，初始化为0，carry跟两个string的末尾数字加在一起，对2取余就是该位数字，对2取商就是进位值，这里把sum跟carry混到了一起**
  
```
class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            s = char(carry % 2 + '0') + s;
            carry /= 2;
        }
        return s;
    }
};

```
