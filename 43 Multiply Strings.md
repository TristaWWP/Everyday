//用两个string表示两个整数，返回他们的积（也是一个二进制字符串）
  
//  a = "2" , b = "3" , sum = "6"
  
  **思路：就像正常的列竖式，两个数的每个位相乘，将他们的结果分别放在两个位上，一个是i+j，一个是他的后一位即i+j+1位，新建一个vector存最终的结果，且vector有m+n位，每位都是零，依次求得位上的数字，存入vector内，甚至连进位都不需要专门计算**
  
```
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> v(m + n, 0);
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + v[p2];
                
                v[p1] += sum / 10;
                v[p2] = sum % 10;
            }
        }
        string res;
        for (auto p : v) if (!(res.size() == 0 && p == 0)) res += (p + '0');
        return res.length() == 0? "0":res;
    }
};
```
