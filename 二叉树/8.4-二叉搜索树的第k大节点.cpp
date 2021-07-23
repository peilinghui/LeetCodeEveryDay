思路描述：

二叉搜索树的一个特征就是中序遍历递增，
所以最简单的办法就是中序遍历二叉搜索树，然后取出倒数第 k 个即可。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
class Solution {
    vector<int> ans;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return ans[ans.size() - k];
    }
};

JS：
var kthLargest = function (root, k) {
    // 中序遍历
    let res = dfs(root, k);
    return res.reverse()[k - 1];
};
let res = [];
const dfs = (root) => {
    if (!root) return;
    dfs(root.left);
    res.push(root.val);
    dfs(root.right)
    return res;
}


解题思路
通过深度优先搜索将树中所有的节点的值加入优先队列（默认大顶堆）中
弹出优先队列中前k-1个元素，然后对首元素即为所求
代码

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
    priority_queue<int> pq;
    void dfs(TreeNode* root){
        pq.push(root->val);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};


 //方法1 递归
     int res=0;
     int n=0;
     int kthLargest(TreeNode* root, int k) {   
         dfs(root,k);
         return res;
     }
     void dfs(TreeNode* root,int k){
         if(root==NULL)return ;
         if(root->right)dfs(root->right,k);
         n++;
         if(n==k)res=root->val;
         if(root->left)dfs(root->left,k);
         return ;
     }


   //方法2 迭代
     int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*>sk;
        int n=0;
        while(!sk.empty()||root){
            while(root){
                sk.push(root);
                root=root->right;
            }
            root=sk.top();
            sk.pop();
            n++;
            if(n==k)return root->val;
            root=root->left;
        }
        return 0;
    }




