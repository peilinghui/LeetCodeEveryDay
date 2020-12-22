82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1),*slow = dummy,*fast = head;
        dummy->next = head;
        while(fast!=NULL&&fast->next!=NULL){ //快指针用于查找相同元素
            if(fast->val!=fast->next->val) {                  
                if(slow->next == fast) slow = fast; //快指针先前没查找到相同数
                else slow->next = fast->next; //先前查找到相同数，将出现相同数的前一个数连接到相同数后第一个不同数 
            }
            fast = fast->next;
        }
        if(slow->next != fast) slow->next = fast->next; // 针对类似[1,1]的情况
        return dummy->next;
    }
};





字节题库 - #82 - 中等 - 删除排序链表中的重复元素II - 2刷
superkakayong
发布于 2020-08-12
3.0k
方法一：迭代。先放C++代码，思路清晰明了。

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummyhead = new ListNode(INT_MAX);
        dummyhead -> next = head;
        ListNode *prev = dummyhead;
        while(prev && prev->next)
        {
            ListNode *curr = prev -> next;
            // 如果curr到最后一位了或者当前curr所指元素没有重复值
            if(!curr->next || curr->next->val != curr->val) prev = curr;
            else
            {
                // 将curr定位到一串重复元素的最后一位
                while(curr->next && curr->next->val == curr->val) curr = curr -> next;
                // prev->next跳过中间所有的重复元素
                prev -> next = curr -> next;
            }  
        }
        return dummyhead -> next;
    }
};
执行结果截图
image.png

方法二：递归。先放C++代码，思路清晰明了。

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        if(head->next->val != head->val)
        {
            // 如果head后面一位的元素的值不等于head的值，就从head->next开始接着处理后面的链表
            head -> next = deleteDuplicates(head -> next);
            return head;
        } 
        else
        {
            // 如果head后面一位的元素的值等于head的值，就跳过所有与head的值相等的元素，从第一个不等于head值的元素开始处理
            ListNode *curr = head;
            while(curr->next && curr->next->val==curr->val) curr = curr -> next;
            return deleteDuplicates(curr -> next);
        }
    }
};