//在某一区间内翻转链表，找到那个区间，计算区间的大小，然后依次翻转，要建立头结点

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n || head == NULL) return head;
        n -= m;
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode *pre = fakehead;
        while(--m) pre = pre ->next;
        ListNode * pstart = pre->next;
        while(n--){
            ListNode *p = pstart->next;
            pstart->next = p ->next;
            p->next = pre->next;
            pre->next = p;
        }
        return fakehead->next;
    }
};
