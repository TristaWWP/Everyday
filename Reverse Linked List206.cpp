//循环算法,迭代，思路就是就地箭头转过来

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (head == NULL) return head;//注意一定要考虑指针是否为空，不然就是思路不周祥
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* p = cur->next;//cur跟p依次后移
            cur->next = pre;//箭头转过来，类似交换两数
            pre = cur;
            cur = p;
        }
        return pre;
    }
};

//递归
ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
