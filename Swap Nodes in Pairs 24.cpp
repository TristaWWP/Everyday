/* 题目描述：交换链表中的相邻节点
input ： 1->2->3->4  output : 2->1->4->3
思路： 首先判断有两个节点存在，这样才能完成交换while(pre->next && pre->next->next)
找到一个temp节点保存第二个节点的值
交换第一个节点和第二个节点
pre移到下一个需要交换的地方
 */

#include<iostream>
#include<vector>

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
        cout << p->data ;
        p = p ->next;
    }
   cout<< endl;
}
ListNode* createList(int n)//创建环链表
{
     ListNode* head = new ListNode(1);
     ListNode* node, *rear;
     rear =head;
     
     for(int i = 2; i < n; ++i)
     {
         //int data;
         //cin >> data;
         node = new ListNode(i);
         rear->next = node;
         rear = node;
     }
    rear->next = NULL;
     return head;
}
 class Solution
 {
     public:
     ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy = new ListNode(0);//创建一个虚拟的头节点
        ListNode* pre = dummy;
        dummy->next = head;
        while(pre->next && pre->next->next)//确保有两个节点存在，这样才能完成交换
        {
            ListNode* temp = pre->next->next;//临时节点保存第二个节点
            pre->next->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;//以上四行完成两个节点的交换
            pre = temp->next;//交换完成，pre后移到下个需要交换的节点
        }
        return dummy->next;
    }
    
 };

 int main()
 {
     Solution s;
     ListNode* l1 = createList(5);
     
     show(l1);
     ListNode* h = s.swapPairs(l1);
     show(h);
     return 0;
 }
