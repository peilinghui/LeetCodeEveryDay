C++ 两种方法（迭代，递归）

解题思路
代码

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
     //方法1 递归
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1==NULL)return l2;
         if(l2==NULL)return l1;-
         if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
     }
        //方法2 迭代
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1; 
        ListNode* res=new ListNode(0);
        ListNode* p=res;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        p->next=l1?l1:l2;
        return res->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(1);
        ListNode* ret = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = l1 == NULL ? l2 : l1;
        return ret->next;
    }
};



