将有序数组转换为二叉搜索树


将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5



将有序数组转换为二叉搜索树
根据中序遍历的序列恢复二叉搜索树

DFS:

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    
    TreeNode* build(vector<int> &nums,int l,int r){
        if(l>r) return NULL;
        int mid = l +(r-l)/2;
        //以升序数组的中间元素作为根节点 root。
        TreeNode* root = new TreeNode(nums[mid]);
        // 递归的构建 root 的左子树与右子树。
        root->left = build(nums,l,mid-1);
        root->right = build(nums,mid+1,r);
        return root;
    }
};

有序链表转换二叉搜索树
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        return buildTree(v, 0, v.size());
    }
    TreeNode * buildTree(vector<int> & v, int begin, int end){
        if(begin == end) return nullptr;
        int middle = (begin+end)/2;
        TreeNode * root = new TreeNode(v[middle]);
        root->left = buildTree(v, begin, middle);
        root->right = buildTree(v, middle+1, end);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    TreeNode * buildTree(ListNode* head, ListNode * tail){
        if(head == tail) return nullptr;
         // 快慢指针找中心节点
        ListNode* slow = head, *fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};



