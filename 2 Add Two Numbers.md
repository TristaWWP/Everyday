 //给出两个用链表表示的数字，各个位置的数字用逆序表示，返回两个数字的加和，同样用链表表示

//342+465 , 2 -> 4 -> 3 + 5 -> 6 -> 4,  sum = 7 -> 0 -> 8

**思路：新建一个链表，把输入的两个链表，从头开始依次每两个相加，结果成为一个新的节点添加到新链表，注意：处理进位问题，且最高位的进位要特殊处理**

```
单链表的定义
struct ListNode {
    int val;//数据域，当前结点的值
    ListNode *next;//指针域，指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}//结构体的构造函数，冒号后面是初始化列表，给成员val初始化为传入的参数x，next初始化为NULL，初始化当前结点值为x，指针为空
};
```

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);//新建链表，创建新元素
        LiseNode* cur = res;//cur指向res，可以获取res所接收的全部元素，res的指针每次都更新
        int carry = 0;//进位初始设为0
        while (l1 || l2) {//两个输入链表不全为空
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 +carry;
            carry = sum / 10;//取商，看是否需要进位
            cur->next = new ListNode(sum % 10);//取余，余数为该节点的数值
            cur = cur->next;//链表依次后移
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return res->next;
    }
};
```
