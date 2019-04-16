//合并两个有序的链表，返回新链表

//Input 1->2->4, 1->3->4

//output 1->1->2->3->4->4

**思路：新建一个链表，比较两个链表的元素值，把较小的那个链到新链表，如果有一个先比较完，剩下的就全部放入新链表，当然也可以用递归，即当L1小，就对L1的下一个节点和L2调用递归函数，返回值赋给L1的next，最终返回L1，反之亦然，都不需要建立新链表**

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1-> next;
            } else{
                tail->next = l2;
                l2 = l2 -> next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
```
