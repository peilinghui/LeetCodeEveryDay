114. 二叉树展开为链表
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
解题思路
根据题目展开图可以看出是前序遍历后的顺序
使用一个vector对每个节点的引用进行保存
遍历vector将每个节点的引用至 下一个vector元素 ，最后一个元素的right 指向NULL
代码

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> arr ;
    // 序遍历二叉树 并保存对每个节点的引用
    void dfs(TreeNode *root){
        if(root == NULL ) return ;
        arr.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }

    // 遍历每个节点重建为链表
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        dfs(root);
        for(int i=0;i<arr.size()-1;i++){
            arr[i]->right = arr[i+1];
            arr[i]->left = NULL;
        }
    }
};


//递归
class Solution {
public:
    TreeNode* res=nullptr;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->left=nullptr;
        root->right=res;
        res=root;
    }
};


解法一: 后序遍历、递归
依据二叉树展开为链表的特点，使用后序遍历完成展开。

PythonC++

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* last = nullptr;
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            auto pre = root->left;
            while (pre->right != nullptr) pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
        return;
    }
};
解法二: 非递归，不使用辅助空间及全局变量
前面的递归解法实际上也使用了额外的空间，因为递归需要占用额外空间。下面的解法无需申请栈，也不用全局变量，是真正的 In-Place 解法。

C++Python

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                while (most_right->right != nullptr) most_right = most_right->right; // 找最右节点
                most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
                root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
                root->left = nullptr; // 将左孩子置为空
            }
            root = root->right; // 继续下一个节点
        }
        return;
    }
};

作者：hellozhaozheng
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/biao-biao-zhun-zhun-de-hou-xu-bian-li-dai-ma-jian-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

