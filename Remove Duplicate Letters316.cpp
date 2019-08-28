//删除字符串中的重复字符 input="bcabc", output="abc"
/* 
思路：hash表+visited结合
1 首先建立一个hash表，里面是所有字符出现的次数
2 每个字符默认设为未访问
3 结果result增加一个初始值0，为了方便比较
4 每循环一次字符，就把hash的次数减1，如果已经访问过，跳出，开始下个字符循环
5 如果没访问过，比较这个字符和result最后一个字符的大小，以及hash次数是否为0，如果已经为0，就加入到result，并且置为访问（这里不断循环直到result最后一个字符是0）
6 返回的是result从1开始后的字符串，为了把0去掉
 */
#include<iostream>
#include<vector>
#include<string>

 using namespace std;

 class Solution
 {
     public:
     string removeDuplicatesLetter(string s)
     {
         vector<int> nums(256,0);//建立一个hash表统计每个字母出现的次数
         vector<bool> visited(256,false);//记录每个字母是否被访问过
         for(char c : s)
         {
             nums[c]++;
         }
         string result = "0";//0的ascii是48
         for(char c : s)
         {
             nums[c]--;//遍历到的字符hash表减1
             if(visited[c]) continue;//如果访问过继续循环，说明该字母已经在结果中并且位置妥当
             while(c < result.back() && nums[result.back()])//没被访问过就和最后一个字符比较，这里当hash值为0的时候就是可以加入字符的时候
             {
                 visited[result.back()] = false;//将最后的字符标记为未访问
                 result.pop_back();//并在结果中删去这个字符
             }
             result += c;//加上当前遍历到的字符
             visited[c] = true;//标记为已访问
         }
        return result.substr(1);//再去掉开头字符串里面的0，加0 是为了第一次比较方便，返回从第一位开始的后缀
     }   
 };

 int main()
 {
     Solution s;
     string str = "bcabc";
     string res;
     res = s.removeDuplicatesLetter(str);
     cout << res;
     return 0;
 }
