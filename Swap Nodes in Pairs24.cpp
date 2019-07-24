//题目描述：交换链表的相邻两个节点

//思路：定义一个pre指针指向头节点，先交换前两个节点，然后pre指针后移，再次交换后面两个



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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        dummy ->next = head;
        while(pre->next && pre->next->next){
            ListNode *temp = pre->next->next;
            pre->next->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            pre = temp->next;
        }
        return dummy->next;
    }
};
