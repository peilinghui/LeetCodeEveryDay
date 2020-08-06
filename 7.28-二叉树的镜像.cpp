
1.主要思路：交换根节点左右子树
2.方法一：递归，双百
3.方法二：栈的迭代，双白
4.方法三：队列的迭代，双百


class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        mirrorTree(root->left);
        mirrorTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};



class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
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




class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
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




