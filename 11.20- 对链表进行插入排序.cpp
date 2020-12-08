对链表进行插入排序

插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 
插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 


输入: 4->2->1->3
输出: 1->2->3->4

  

//基本的插入排序。
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode * pre = new ListNode(-1);
        pre -> next = head;

        ListNode * tail = head;
        ListNode * node = head->next; 

        while(node){
            if(node->val < tail->val){
                ListNode * cur = pre;
                while(cur->next && node->val >  cur->next->val){
                    cur = cur->next;
                }
                tail->next = node->next;
                node->next = cur->next;
                cur->next =  node;
                node=tail->next;

            }else{
                tail = tail->next;
                node = tail->next;
            }
        }
        return pre->next;
    }
};



class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next) {return head;}

        ListNode* dummy = new ListNode(INT_MIN);
        dummy -> next = head;
        ListNode* tail = head, *sort = head -> next; // tail指向已排好序部分的尾结点；sort是下一个待排序的结点

        while(sort) {
            if(sort -> val < tail -> val) {
                ListNode* pos = dummy; // 定义一个pos指针，用于每次从头（dummy处）寻找该插入sort的结点的位置。比如1->3，sort是2，那pos就在1处。
                while(pos -> next -> val < sort -> val) {pos = pos -> next;} // 将pos定位到已排好序的且比sort小的部分中的最大的那个结点。

                tail -> next = sort -> next; // 断链。比如dummy->4->2->1->3，tail是4，sort是2，则让4->1，把2拎出来。
                sort -> next = pos -> next; // pos此时在dummy处（因为4大于2），则让 2->4。
                pos -> next = sort; // 上一步相当于断掉了dummy->4，现在重新接起来：dummy->2->4->1->3。

                sort = tail -> next; // 让sort重新回到下一个待排序的结点处
            }
            else {
                tail = tail -> next;
                sort = sort -> next;
            }
        }

        ListNode* res = dummy -> next;
        delete dummy;
        return res;
    }
};

