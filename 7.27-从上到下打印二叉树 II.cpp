两个思路，一个BFS，一个DFS，很经典的层序遍历题。
唯一注意的是要把每一层放到一起，需要维护一个level进行保存。
DFS记得使用引用&，不然就得维护一个全局变量了。
代码
DFS：
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res,0);
        return res;
    }
    void dfs(TreeNode* root,vector<vector<int>>& res,int level)
    {
        if(!root) return;
        if(level>=res.size()) res.emplace_back(vector<int>());
        res[level].emplace_back(root->val);
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
    }
};



BFS:

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(q.size())
        {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* rt=q.front();q.pop();
                if(!rt) continue;
                level.push_back(rt->val);
                if(rt->left) q.push(rt->left);
                if(rt->right) q.push(rt->right);
            }
            if(level.size()!=NULL) res.push_back(level);
        }
        return res;
    }
};
