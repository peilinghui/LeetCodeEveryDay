class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1); 
        dummy->next = head; //建立虚拟头节点
        ListNode* cur = dummy;
        while(cur->next) 
            if(cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        return dummy->next;
    }
};


class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==NULL)return NULL;
        if(head->val==val)return head->next;
        ListNode *p=head;
        while(p->next){
            if(p->next->val==val){
                p->next=p->next->next;
                break;
            }
            p=p->next;
        }
        return head;
    }
};
