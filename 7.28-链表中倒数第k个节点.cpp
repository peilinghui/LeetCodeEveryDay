
1.快指针和慢指针相差k
2.快指针到达链尾，慢指针所指方向就是倒数第k个链表

代码

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0; i < k; i ++) cur = cur->next;
        while(cur) {
            cur = cur->next;  //快指针
            head = head->next;  //慢指针
        }
        return head;
    }
};


快慢指针
定义两个指针，快指针 fastfast， 慢指针 lowlow .
让 fastfast 先向前移动 kk 个位置，然后 lowlow 和 fastfast 再一起向前移动 .
当 fastfast 到达链表尾部，返回 lowlow .
代码

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* low = head;
        while (fast != NULL) {
            fast = fast->next;
            if (k == 0) {
                low = low->next;
            } else {
                k--;
            }
        }
        return low;        
    }
};
递归
先一直递归到链表尾部，再返回
定义位置变量 pospos ，每次函数返回时 pos++pos++
当 pos == kpos==k 时，说明此时递归函数位于第 kk 个结点位置，返回该结点
代码

class Solution {
public:
    int pos = 0;
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL) {
            return 0;
        }
        ListNode* ret = getKthFromEnd(head->next, k);
        pos++;
        if (pos == k) {
            return head;
        }
        return ret;    
    }
};

