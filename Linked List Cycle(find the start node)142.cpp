/*题目描述：找到链表中环节点
input ： 3->2->0->-4 output : 1
思路：找到头节点和相遇点到环起始点的关系，可以证明相遇点到环起始点和头节点到环起始点的距离相等
证明：头节点到环节点距离x，环节点到相遇点y，相遇点到环节点z，快指针走的距离是慢指针的2倍
S慢 = x + y + nC    S快 = 2S慢 = x + y + mC = 2x + 2y + 2nC 
x = （m - 2n）C - y = （m - 2n - 1）C  + C - y =（m - 2n - 1）C + z
所以当相遇的时候，一个指针从头节点开始走，一个指针从相遇点开始走，再次相遇的位置就是环节点，因为他们都走过了很多圈+z的距离
 */
#include<iostream>

using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(NULL){}
};
void show(ListNode* head)
{
    if(head == NULL)
    {
        cout << "NULL";
    }
    ListNode* p = head;
    while(p)
    {
        cout << p->data;
        p = p->next;
        if(p->data == head -> data)//加个判断环中的元素打印完就退出。
                break;
    }
    cout << endl;
}
ListNode* createList(int n)//尾插法创建链表
{
    ListNode* head = new ListNode(0);
    ListNode* newNode;
    ListNode* rear = head;
    for(int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        newNode = new ListNode(data);
        rear->next= newNode;
        rear = newNode;
    }
    rear->next = head->next;//让最后一个元素指向头节点，形成环
    return head->next;
}
class Solution{
public:
    ListNode* findStartNode(ListNode* head)
    {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow != fast)//慢指针从头开始走
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
int main()
{
    ListNode* l = createList(4);
    show(l);
    Solution s;
    ListNode *l1 = s.findStartNode(l);
    show(l1);
    return 0;
}
