234. 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        ListNode *fast = head, *slow = head;
        ListNode *p, *pre = NULL;
        while(fast && fast->next){
            p = slow ; slow=slow->next; fast=fast->next->next;//快慢指针
            p->next = pre; pre=p;//反转链表
        }
        if(fast) slow = slow->next;
        while(p){
            if(p->val != slow->val) return 0;
            p=p->next; slow = slow->next;
        }
        return 1;
    }
};