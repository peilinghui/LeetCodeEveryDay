1290. 二进制链表转整数
给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。

 

示例 1：



输入：head = [1,0,1]
输出：5
解释：二进制数 (101) 转化为十进制数 (5)




由于链表中从高位到低位存放了数字的二进制表示，因此我们可以使用二进制转十进制的方法，在遍历一遍链表的同时得到数字的十进制值。

C++Python3

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans = ans * 2 + cur->val;
            cur = cur->next;
        }
        return ans;
    }
};
复杂度分析

时间复杂度：O(N)O(N)，其中 NN 是链表中的节点个数。

空间复杂度：O(1)O(1)。


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head != NULL){
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};


c++ 位运算

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = 0;
        while(head != NULL) {
            n = (n << 1) + head->val;
            head = head->next;
        }
        return n;
    }
};

