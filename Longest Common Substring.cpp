//最长公共字串（不同于最长公共子序列，字串是连续的）
//str1 = "abcde"
//str2 = "abcdfe",最长公共字串是abcd，长度为4

/* 维护一个二维vector的dp数组
   dp[i][j]表示公共子串中A字符串中第i个字符结尾，B字符串中第j个字符结尾的长度，
   找到重复子问题，判断A的第i个元素B的第j个元素是否相同---即判断A[i - 1]和 B[j -1]是否相同，就要判断A[i - 2]和 B[j -2]是否相同，等等等，
   如果最开始的A[i - 1]和 B[j -1]相同，那么公共子串的长度就是dp[i - 1][j- 1] + 1，相当于在两个字符串都去掉一个字符时的最长公共子串再加 1；
   否则最长公共子串取0。所以整个问题的初始状态为：
                                        dp[i][0]=0,dp[0][j]=0
相应的状态转移方程为：方程的循环中ij一定从1开始，不能从0开始，因为有i-1  */
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int LCS(string A,string B)
{
    int n = A.size();
    int m = B.size();
    int rs = 0;
    vector<vector<int> > dp(n+1,vector<int> (n+1));
    for (int i = 1; i <=n; i++) {//一定要记住i从1开始，不能从0开始，因为后面有i-1
		for (int j = 1; j <= m; j++) {
		    if (A[i-1] == B[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;//状态转移方程
				rs = rs > dp[i][j] ? rs : dp[i][j]; //每次更新记录最大值
			}
			else {
				dp[i][j] = 0;
			}
        }
    }
        return rs;
}
int main()
{
    string str1 = "abcde";
    string str2 = "abcdfe";
    int result;
    result = LCS(str1,str2);
    cout << result;
    return 0;
}
