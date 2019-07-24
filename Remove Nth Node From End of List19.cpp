　//题目描述：删除链表的倒数第n个节点，要求只能进行一次遍历

//思路：首先考虑全面，判空，链表不为空
//使用两个指针，类似于快慢指针，快指针第一次走n步，如果没走到末尾，之后的每一步快指针跟慢指针一起走，这样慢指针永远比快指针慢n，
//这样快指针走到末尾，慢指针的地方就是要删除节点的前一个节点


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head ->next) return NULL;
        ListNode *pre = head;
        ListNode *cur = head;
        for(int i = 0; i < n; ++i){
            cur = cur->next;
        }
        if(!cur){
            return head->next;
        }
        while(cur->next){
            
                cur = cur->next;
                pre = pre->next; 
            
        }
        pre->next = pre->next->next;
        return head;
    }
};
