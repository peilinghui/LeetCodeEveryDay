递归：

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      dfs(root);
      return root;
    }
private:
    void dfs(TreeNode* root){
        if(root){
            swap(root->left, root->right);
            dfs(root->left);
            dfs(root->right);
        }
    }
};



栈的迭代：
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root) stk.push(root);
        while(stk.size()) {
            TreeNode* tr = stk.top();
            stk.pop();
            swap(tr->left, tr->right);
            if(tr->left) stk.push(tr->left);
            if(tr->right) stk.push(tr->right);
        }
        return root;
    }
};


队列的迭代：
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(q.size()) {
            TreeNode* tr = q.front();
            q.pop();
            swap(tr->left, tr->right);
            if(tr->left) q.push(tr->left);
            if(tr->right) q.push(tr->right);
        }
        return root;
    }
};

将上述的递归代码改为迭代方式：

类似二叉树的层序遍历，每次向队列中添加当前层的节点；
不断弹出队列，将队首元素的左右孩子进行交换 swap
迭代代码

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(!root) return nullptr;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
          int size = q.size();
          while(size--){
              TreeNode* tmp =  q.front();
              q.pop();
              if(tmp){
                  swap(tmp->left, tmp->right);
                  q.push(tmp->left);
                  q.push(tmp->right);
              }
          }
      }
      return root;
    }




