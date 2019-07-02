//在特定的时间复杂度O(n log n)给链表排序

//Input -1->5->3->4->0

//Output -1->0->3->4->5

**思路:排序算法有插入、选择、堆、快速、冒泡、归并等，时间复杂度在O(n log n)是快速、归并、堆。归并是把两个有序序列合并成一个，两两合并，方法将链表分为两段的方法时fast-slow法，用两个指针，一个快指针每次走两步，一个慢指针每次走一步，直到快指针走到末尾，慢指针在的位置就是链表的中间位置，这样就分成两段，然后合并，用递归的话可以让代码更简洁**
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeTwoLists(sortList(head), sortList(slow));  
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);//头结点
        ListNode *tail = &dummy;
        
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
        return dummy.next;
    }
};
```
