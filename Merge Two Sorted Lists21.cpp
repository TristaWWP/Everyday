/* 题目描述：合并有序链表
input 1->2->4 ， 1->3->4 output 1->1->2->3->4->5
思路：先判断两个链表是否有一个为空
建立一个虚拟的头节点
当两个链表都存在的时候，比较data的值，小的那个节点就放在head后面
head节点不断向后增加
当有一个节点为空的时候，就把剩余的节点整体移过来，返回虚拟头节点的next

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
     
     for(int i = 0; i < n; ++i)
     {
         int data;
         cin >> data;
         node = new ListNode(data);
         rear->next = node;
         rear = node;
     }
    rear->next = NULL;
     return head;
}
 class Solution
 {
     public:
     ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
     {
         if(l1 == NULL) return l2;
         if(l2 == NULL) return l1;
         ListNode* dummy = new ListNode(0);//建立一个虚的头节点，值为0
         ListNode* head = dummy;

         while(l1 && l2)
         {
             if(l1->data < l2->data)
             {
                 head ->next = l1;
                 l1 = l1->next;
             }
             else
             {
                 head->next = l2;
                 l2 =  l2 ->next;
             }
             head = head ->next;
         }
         head ->next = l1 ? l1 : l2;
         return dummy->next; 
     }
    
 };

 int main()
 {
     Solution s;
     ListNode* l1 = createList(2);
     show(l1);
     ListNode* l2 = createList(2);
     show(l2);
     ListNode* h = s.mergeTwoList(l1,l2);
     show(h);
     return 0;
 }
