/* 题目描述：移除链表的倒数第N个节点
input 1->2->3->4->5,n=2;output 1->2->3->5
思路：关键在于如何巧妙找到倒数第N个节点，依旧是快慢指针
首先要判断链表不为空，head的next至少要存在
快指针先走N步
此时如果快指针为空，则N为链表长度，返回的是head->next开始的链表
反之如果快指针不为空，慢指针开始和快指针一起，走一步，直到快指针走到末尾
此时慢指针在的位置就是要删除节点的前一个
这时断开链表就可以，慢指针跳过这个节点slow ->next = slow->next->next;

 */
#include<iostream>
#include<vector>
#include<string>

 using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
    ListNode(int x):data(x), next(NULL){}
};

//输出链表
void show(ListNode* head)
{
    if(head == NULL)
    {
        cout << "nullptr" << endl;
    }
    ListNode* p = head;
    while(p)
    {
        cout << p->data << endl;
        p = p ->next;
    }
   
}
 class Solution
 {
     public:
     ListNode* removeNthFromEnd(ListNode* head, int n)
     {
         if(!head->next) return NULL;
         ListNode* fast = head;
         ListNode* slow = head;
         for(int i = 0; i < n ; ++i)//快指针走N步
         {
            fast = fast->next;
         }
         if(!fast)
         {
             return head->next;//如果此时链表刚好为空，证明n是链表的长度，这时返回的是head->next
         }
         while(fast->next)//此时快慢指针一起走，当快指针走到末尾，慢指针在的位置就是要删除节点的前一个
         {
             fast = fast->next;
             slow = slow->next;
         }
         slow ->next = slow->next->next;
         return head;
     }
    
 };

 int main()
 {
     Solution s;
     ListNode* head = new ListNode(1);
     ListNode* node, *p;
     p =head;
     for(int i = 2; i <= 5; ++i)
     {
         node = new ListNode(i);
         p->next = node;
         p = node;
     }
     show(head);
     ListNode* h = s.removeNthFromEnd(head,2);
     show(h);
     return 0;
 }
