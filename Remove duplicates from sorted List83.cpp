/* 题目描述：删除有序链表中的重复元素
input：1->1->2->3->3  output: 1->2->3
思路：直接判断当前节点和下一个节点值是否相等，相等就越过这个节点，然后依次遍历链表
注意当用到next的时候要判断是否还有下一个节点
 */
#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
    ListNode(int x): data(x), next(NULL){}
};
void show(ListNode* head)
{
    if(head == NULL)
    {
        cout << "空";
    }
    ListNode* p = head;
    while(p)
    {
        cout << p ->data;
        p = p->next;
    }
    cout << endl;
}
ListNode* creatList(int n)
{
    ListNode* head = new ListNode(1);
    ListNode* rear= head;
    ListNode* newNode;
    for(int i = 0; i < n; ++i){
        int data;
        cin >> data;
        newNode = new ListNode(data);
        rear ->next = newNode;
        rear = newNode;
    }
    rear ->next = NULL;
    return head;
}
ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL) return NULL;
    ListNode* cur = head;
    while(cur)
    {
        while(cur->next && cur->data == cur->next->data)
        {
            cur->next = cur->next->next;
        }
        cur = cur->next;
    }
    return head;
}
int main()
{
    ListNode* l = creatList(4);
    show(l);
    deleteDuplicates(l);
    show(l);
    return 0;
}
