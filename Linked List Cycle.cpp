/* 
判断链表是否有环：快慢指针法
1. 首先要判断头节点和头节点的next都不为空（这样目的是链表存在环，如果为空，即false，不存在环）
2. 快慢指针都指向头节点head
3. 循环当fast的next和fast的next的next都存在时，开始走路（确保快指针有后继）
4. 快指针每次走两步:fast = fast->next->next;慢指针走一步slow = slow->next;
5. 当快慢指针相等的时候，就证明有环
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
        cout << "nullptr"<<endl;
    }
    else
    {
        ListNode *p = head;
        while (p)
        {
            cout << p->data << endl;
            p = p->next;
            if(p->data == head -> data)//加个判断环中的元素打印完就退出。
                break;
        }
    }
}
 class Solution
 {
     public:
     bool hasCycle(ListNode *head)
     {
         if(head == NULL || head->next == NULL) return false;
         ListNode* fast = head;
         ListNode* slow = head;
         while(fast->next  && fast->next->next)
         {
             fast = fast->next->next;
             slow = slow->next;
             if(fast == slow)
                return true;
         }
        return false;
     }  
 };

ListNode* createList(int num)//创建环链表
{
    if(num <= 0)
        return NULL;
     ListNode* head = new ListNode(1);
     ListNode* node, *rear;
     rear =head;
     for(int i = 2; i <= num; ++i)
     {
         node = new ListNode(i);
         rear->next = node;
         rear = node;
     }
    
     rear->next = head;//让最后一个元素指向头节点，形成环
     return head;
}
 int main()
 {
     Solution s;
     ListNode* L =NULL;
     L = createList(8);
     show(L);
     if(s.hasCycle(L))
     {
         cout<< "True";
     }
     else
     {
       cout<< "False";
     }
     
     
     return 0;
 }
