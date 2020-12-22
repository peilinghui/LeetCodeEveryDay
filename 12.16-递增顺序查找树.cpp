897. 递增顺序查找树
给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

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
            \
             7
              \
               8
                \
                 9


利用中序遍历的性质：二叉搜索树的中序遍历得到一个递增的序列。
然后根据要求构建一棵树：
先定义一个节点ans，用于返回整棵树
在定义一个节点cur，表示正在操作的节点。按照题目要求，只需要根据数组中的值，依次在右子树中构造相应的节点即可。



class Solution {
public:
    void inOrder(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)  return ;
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inOrder(root,res);
        TreeNode *ans = new TreeNode(0),*cur=ans;
        for(int v:res)
        {
            cur->right = new TreeNode(v);
            cur=cur->right;
        }
        
        return ans->right;
    }
};


