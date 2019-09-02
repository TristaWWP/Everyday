/*题目描述：给链表排序，想到
input ： 4->2->1->3 output : 1->2->3->4
思路：要求在O(nlgn)时间复杂度内，合适的排序方法快排，堆排，归并，还有O(n)的基数排序桶排序
链表的特点不能通过下标访问，堆排一般是数组形式，所以最好采用归并排序（递归操作）
温故而知新：回顾下归并排序，将两个已经排好序的序列合并成一个有序序列merge，有递归和非递归两种，两路归并就是两两合并
那么对于无序链表来说，怎么才是有序链表，当然是只有一个节点的是有序链表
所以就把问题不断分解，直到链表内只有一个节点
一个链表不断分成两半，直到分到只有一个节点，然后往上回溯，合并
链表分成两个中点使用快慢指针法，快指针走两步，慢指针走一步，当快指针走到末尾，慢指针就来到链表中点
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
    rear->next = NULL;
    return head->next;
}
class Solution{
public:
    ListNode* sortList(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* fast = head, *slow = head, *pre = head;
        while(fast && fast->next)//快指针走两步慢指针走一步，快指针走到链表末尾，慢指针刚好走到中间位置
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeList(sortList(head), sortList(slow));
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2)//合并链表
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(l1 && l2)
        {
            if(l1->data < l2->data)
            {
                head ->next = l1;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;            
        }
        head ->next = l1 ? l1 : l2;
        return dummy->next;
    }

};
int main()
{
    ListNode* l = createList(4);
    show(l);
    Solution s;
    ListNode *l1 = s.sortList(l);
    show(l1);
    return 0;
}
