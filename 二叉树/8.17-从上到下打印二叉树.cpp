
剑指 Offer 32 - I. 从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]


DFS:
class Solution {
    vector<int> res;
public:
    vector<int> levelOrder(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
         if(!root) return;
            res.emplace_back(root->val);
            dfs(root->left);
            dfs(root->right);
    }
};


BFS:

public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* rt=q.front();q.pop();
                if(!rt) continue;
                res.push_back(rt->val);
                if(rt->left) q.push(rt->left);
                if(rt->right) q.push(rt->right);
            }
        }
        return res;
    }
