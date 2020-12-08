面试题 04.04. 检查平衡性
实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


示例 1:
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。
示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
返回 false 。


class Solution {
public:
    int depth(TreeNode* root)//计算以root为根节点的子树的最大深度
    {
        if(root==NULL)  return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)  return true;
        
        if(abs(depth(root->left) - depth(root->right)) < 2)//如果根节点的左右子树高度差小于2
            return isBalanced(root->left) && isBalanced(root->right);//继续递归判断左孩子右孩子
        return false;
    }
};

//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


//BFS 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                TreeNode* node = q.front(); 
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans ++;
        }
        return ans;
    }
};

//DFS

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int ans = 1;
        while(!s.empty()){
            pair<TreeNode*, int> temp = s.top();
            s.pop();
            TreeNode* node = temp.first;
            int height = temp.second;
            if(node->right){
                s.push({node->right, height + 1});
                ans = max(ans, height + 1);
            }
            if(node->left){
                s.push({node->left, height + 1});
                ans = max(ans, height + 1);
            }
        }
        return ans;
    }
};
