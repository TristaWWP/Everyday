//合并K个有序链表，返回一个新的有序链表

//Input ： [1->4->5,  1->3->4, 2->6]

//Output : [1->1->2->3->4->4->5->6]

**思路:利用了之前的合并有序链表，合并多个就要两个两个合并，效率要高就要用到分治法 Divide and Conquer，就是不停的对半划分，比如k个链表先划分为合并两个k/2个链表的任务，再不停的往下划分，直到划分成只有一个或两个链表的任务，开始合并。如合并6个先分别合并1和4,2和5,3和6。这样下一次只需合并3个链表，再合并1和3，最后和2合并**

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int n = lists.size();
        while(n>1){
            int k = (n+1)/2;
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
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
