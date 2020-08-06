双指针
定义两个指针： prepre 和 curcur ；prepre 在前 curcur 在后。
每次让 prepre 的 nextnext 指向 curcur ，实现一次局部反转
局部反转完成之后， prepre 和 curcur 同时往前移动一个位置
循环上述过程，直至 prepre 到达链表尾部

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
};

妖魔化的双指针
原链表的头结点就是反转之后链表的尾结点，使用 headhead 标记 .
定义指针 curcur，初始化为 headhead .
每次都让 headhead 下一个结点的 nextnext 指向 curcur ，实现一次局部反转
局部反转完成之后，curcur 和 headhead 的 nextnext 指针同时 往前移动一个位置
循环上述过程，直至 curcur 到达链表的最后一个结点 .

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return NULL; }
        ListNode* cur = head;
        while (head->next != NULL) {
            ListNode* t = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = t;
        }
        return cur;
    }
};

递归
使用递归函数，一直递归到链表的最后一个结点，该结点就是反转后的头结点，记作 retret .
此后，每次函数在返回的过程中，让当前结点的下一个结点的 nextnext 指针指向当前节点。
同时让当前结点的 nextnext 指针指向 NULLNULL ，从而实现从链表尾部开始的局部反转
当递归函数全部出栈后，链表反转完成。

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};

