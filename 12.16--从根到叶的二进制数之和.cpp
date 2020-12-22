1022. 从根到叶的二进制数之和
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

返回这些数字之和。题目数据保证答案是一个 32 位 整数。

 

示例 1：


输入：root = [1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22




//深度优先遍历
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumRootToLeaf = function(root) {
    const dfs = (root, path) => {
        if (!root) return
        path += root.val.toString()
        if (!root.left && !root.right) {
            paths.push(path)
        }
        else {
            dfs(root.left, path)
            dfs(root.right, path)
        }
    }
    let paths = []
    dfs(root, "")
    let res = 0
    for (let path of paths) {
        
        res += parseInt(path, 2)
    }
    return res
};


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
    void f(TreeNode* root,int &sum,int temp)
    {
        int t=0;
        if(!root) return;
        if(root->left==NULL&&root->right==NULL)
        {
            sum+=temp*2+root->val;
            return ;
        }
        t=temp*2+root->val;
        f(root->left,sum,t);
        f(root->right,sum,t);
    }
    int sumRootToLeaf(TreeNode* root) {
          int sum=0,temp=0;
          f(root,sum,temp);
          return sum;
    }
};


class Solution {
public:
    const long M = 1e9 + 7;
    void dfs(TreeNode* root, long p, long& res) {
        if (root == NULL) return;
        p = (p << 1) | root->val;
        if (root->left == NULL && root->right == NULL) {
            res += p;
            res %= M;
            return;
        }
        dfs(root->left, p, res);
        dfs(root->right, p, res);
    }
    int sumRootToLeaf(TreeNode* root) {
        long res = 0;
        long p = 0;
        dfs(root, p, res);
        return res;
    }
};




遍历二叉树的过程中直接计算每条路径的二进制的值，并加到总和上

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
    int sum = 0;
    void preAccess(TreeNode* root, int curSum)
    {
        if(root == NULL) return ;
        
        curSum = curSum * 2 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += curSum;
        }
        
        preAccess(root->left,curSum);
        
        preAccess(root->right,curSum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        preAccess(root,0);
        
        return sum;
    }
};

class Solution {
public:
    // 深度优先遍历 迭代
    vector<vector<int>> all_path;
    void get_res(TreeNode* root, vector<int>& res){
        if (root->left == nullptr && root->right == nullptr){
            res.push_back(root->val);
            all_path.push_back(res);
            return;
        }
        res.push_back(root->val);
        if (root->left != nullptr){
            get_res(root->left, res);
            res.pop_back();
        }
        if(root->right != nullptr){
            get_res(root->right, res);
            res.pop_back();
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        // vector<vector<int>> res;
        vector<int> res;
        get_res(root, res);
        // 计算结果
        int sum = 0;
        for (int i = 0; i < all_path.size(); i++){
            // 计算 all_path[i]
            int temp = 0;
            for (int j = 0; j < all_path[i].size(); j++){
                temp += all_path[i][j] * pow(2, all_path[i].size() - j - 1);
            }
            sum += temp;
        }
        return sum;
    }
};

