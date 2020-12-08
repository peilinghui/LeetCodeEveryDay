
面试题 02.03. 删除中间节点
实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

 

示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f

题目给定结点，通过将结点的val值改为下一个节点的val，并将该节点的next改为下一个结点的next来覆盖要删除的结点

这里要注意以下几点：

要删除的这个节点就是给定的这个节点，由于无法访问上一个节点，所以这个节点是删除不掉的。
考虑用当前节点覆盖下一个节点，然后把下一个节点删除。也就是需要将下一个节点的值赋值给当前节点，然后把下一个节点删除。
需要以下两步操作：

下一个节点的值赋值给当前节点：node->val = node->next->val;
删除下一个节点：node->next = node->next->next;


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
    void deleteNode(ListNode* node) {
       node->val = node->next->val;
       node->next = node->next->next;
    }
};



