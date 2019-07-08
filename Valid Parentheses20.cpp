//用栈实现，先读入左字符串，然后遇到右字符串并且栈顶是对应的左字符串，就pop，直到遍历结束
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack1;
        for (char &c : s) {
           if (c == '(' || c == '{' || c == '[') {
               mystack1.push(c);
           }
            else {
                if(mystack1.empty()) return false;
                if(c == ')' && mystack1.top() != '(') return false;
                if(c == '}' && mystack1.top() != '{') return false;
                if(c == ']' && mystack1.top() != '[') return false;
                mystack1.pop();
            }
        }
        return mystack1.empty();
    }
};
