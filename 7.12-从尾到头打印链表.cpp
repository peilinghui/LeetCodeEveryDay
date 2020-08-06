图解递归+反转+堆栈（Python3、C++）
腐烂的橘子🍊
发布于 2020-03-03
2.8k
思路一：反转
从头到尾将链表打印到数组中，返回反转后的结果即可。
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
复杂度分析
时间复杂度：O(n)O(n)，reverse()reverse() 的时间复杂度为 O(n)O(n)，遍历了一遍数组，复杂度也为 O(n)O(n)。
空间复杂度：O(n)O(n)，使用了额外的 res。


思路二：递归
假设 head.next 已经排好序，那么只需将 head 添加到末尾即可。
其中，head.next 部分可以使用递归来实现，递归的终止条件为 head 为空。
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if (!head) return res;
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
复杂度分析
时间复杂度：O(n)O(n)，递归 nn 次，时间间复杂度为 O(n)O(n)，递归函数中的操作时间复杂度为 O(1)O(1)，总时间复杂度为 O(n)\times O(1)=O(n)O(n)×O(1)=O(n)。
空间复杂度：O(n)O(n)，递归将占用链表长度的栈空间。


思路三：堆栈
利用堆栈先进后出的特点，先依次将元素压入堆栈中，然后将所有元素从堆栈中弹出，即可实现反转。
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        while(head){// push
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){ // pop
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
复杂度分析
时间复杂度：O(n)O(n)，pushpush 的间复杂度为 O(n)O(n)，poppop 的间复杂度为 O(n)O(n)。
空间复杂度：O(n)O(n)，使用了额外的 res 和 堆栈。
视频







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
    vector<int> reversePrint(ListNode* head) {
        stack<int> a;
        vector<int> b;
        //while(head != nullptr){  //判断是否head已经空了
        while(head){
            a.push(head->val);
            head=head->next;
        }
       // while(a.empty()==false){//判断stack是否已经空了
        while(!a.empty()){
            b.push_back(a.top());
            a.pop();
        }
        return b;
    }
};

作者：jia-you-jia-you-5
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/can-kao-de-jie-fa-yong-stackcun-chu-mei-ge-nodede-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。