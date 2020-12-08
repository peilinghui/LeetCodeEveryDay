返回倒数第 k 个节点

实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4


class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if(head->next == NULL) return head->val;
        ListNode *slow = head, *fast = head;
        while(k--){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow->val;
       
    }
};

时间复杂度O(n),空间复杂度O(1)


剑指 Offer 22. 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

 

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i=0;i<k;i++) cur=cur->next;
        while(cur){
            cur = cur->next;
            head = head->next;
        }
        return head;
    }
};