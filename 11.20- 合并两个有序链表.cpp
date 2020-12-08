21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4


//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
};

//迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(1);
        ListNode *ret = head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                head->next = l1;
                l1=l1->next;
            }else{
                head->next = l2;
                l2=l2->next;
            }
            head= head->next;
        }
        head->next = l1 == NULL ? l2:l1;
        return ret->next;
    }
};