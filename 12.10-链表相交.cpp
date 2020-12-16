面试题 02.07. 链表相交


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA) {
            swap (lenA, lenB);
            swap (curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};


Method3:双指针
使用两个指针分别指向headA和headB，当一个指针先到达末尾时，就让它指向另一个指针的头部，如果相遇的话就是交点；否则的话两个指针都走了两个链表的长度，返回null。

code

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA=headA,*curB=headB;
        while(curA != curB)
        {
            if(curA==NULL)
                curA=headB;
            else
                curA=curA->next;
            if(curB==NULL)
                curB=headA;
            else
                curB=curB->next;
        }
        return curA;
    }
};
