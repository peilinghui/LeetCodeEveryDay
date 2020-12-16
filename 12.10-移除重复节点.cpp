面试题 02.01. 移除重复节点
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]



1.用set去重和查重

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> set; 
        ListNode* cur = head; 
        while(cur && cur->next){ //空节点则返回空
            set.insert(cur->val);
            if(set.count(cur->next->val)) cur->next = cur->next->next;  //找到相同元素，则删除链表
            else cur = cur->next; //开始循环
        }
        return head;
    }
};



   ListNode* removeDuplicateNodes(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode* cur = head;

        while (cur)
        {
            ListNode* prev = cur;
            while (prev->next) //遍历到链表尾，删除值等于cur->val的所有节点
            {
                if (prev->next->val == cur->val)
                {
                    prev->next = prev->next->next;
                }
                else
                {
                    prev = prev->next;
                }
            }
            
            cur = cur->next;
        }

        return head;
    }



    利用哈希
哈希表存储出现过的节点值，如果当前节点出现过，就删掉。
时间复杂度：O(n)O(n)


const removeDuplicateNodes = (head) => {
  if (head == null) {
    return head;
  }
  const set = new Set();
  set.add(head.val);  

  let prev = head;     // head是存在的，赋给prev
  let cur = head.next; // head是存在的，它的next赋给cur

  while (cur) {
    if (set.has(cur.val)) { // 如果当前节点是重复的
      prev.next = cur.next; // 让prev的next直接指向cur的next，完成删除
      cur = cur.next;       // 更新一下cur
    } else {
      set.add(cur.val);     // 当前节点是第一次出现，存储一下
      prev = prev.next;     // prev和cur都更新一下，跳到下一个
      cur = cur.next;
    }
  }
  return head; // 返回删除重复节点后的链表
};
双指针
固定p指针，右侧q指针扫描，然后移动p，指针q再次扫描
时间复杂度 O(n^2)O(n 
2
 )，不太理想。


const removeDuplicateNodes = (head) => {
  let p = head;
  while (p) {
    let q = p;
    while (q.next) {
      if (q.next.val == p.val) {
        q.next = q.next.next;
      } else {
        q = q.next;
      }
    }
    p = p.next;
  }
  return head;
};



