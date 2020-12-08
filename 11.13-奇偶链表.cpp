328. 奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL


双指针法求解，一个指向奇数链表，另一个指向偶数链表，每次迭代后注意奇偶连接，然后迭代进行。
注意考虑pre和cur进行一次迭代后如何衔接，ListNode* tmp=pre->next表明每次衔接点的位置（如果用cur进行衔接的话会丢失一些元素），最后用pre->next->next=tmp可以保证奇偶链表衔接正常。


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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre=head,*cur=head->next;
        while(cur && cur->next){
            ListNode* tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;//每次走2步，保证它指的点是奇数点
            pre->next->next=tmp;
            
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};


设cur为当前已构造好序列的最后一个结点，设j为奇数结点指针（它负责找后面的奇数结点）
把每找到的j结点连在cur结点后。


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        if(head->next->next==NULL)return head;
        ListNode *cur=head;
        ListNode *j=head;
        ListNode *prej=NULL;
        //cur，j点初始都在第一个点
        while(j!=NULL)
        {
            if(j->next==NULL)break;
            if(j->next->next==NULL)break;
            prej=j->next;
            j=j->next->next;
            //j每次走2步，保证它指的点是奇数点
            
            //将j(奇数)点插入到cur点后，同时j点原来的位置要 **“顺延下去”** 
            ListNode* tp=cur->next;
            cur->next=j;
            prej->next=j->next;
            j->next=tp;
            cur=j;
            j=prej;
        }
        return head;
    }
};
O(n),O(1)


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        // 定义奇偶位置
        ListNode *first = head;
        ListNode *second = head -> next;
        ListNode *cur = head -> next;
        while(cur && cur -> next != nullptr){
            ListNode *temp = cur -> next;
            cur -> next = cur -> next -> next;
            first -> next = temp;
            temp -> next = second;
            first = temp;
            cur = cur -> next;
        }
        return head;
    }
};



