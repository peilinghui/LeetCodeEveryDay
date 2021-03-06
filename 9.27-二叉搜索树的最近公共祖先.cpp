
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]



示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。


根据二叉搜索树性质：如果 p.val 和 q.val 都比 root.val 小，则 p、q 肯定在 root 的左子树。
那问题规模就变小了，递归左子树就行！
如果 p.val 和 q.val 都比 root.val 大，递归右子树就行！
其他情况，root 即为所求！那么简单吗？为什么？
只要不是 p.val 和 q.val 都大于(小于) root.val，即只要 p, q 不同处在 root 的一个子树
就只有这三种情况：
p 和 q 分居 root 的左、右子树。
root 就是 p，q 在 p 的子树中。
root 就是 q，p 在 q 的子树中
而这三种情况，p 和 q 的最近公共祖先都是 root！是不是很简单！
递归 代码
jsgo

const lowestCommonAncestor = (root, p, q) => {
    if (p.val < root.val && q.val < root.val) {
        return lowestCommonAncestor(root.left, p, q);
    }
    if (p.val > root.val && q.val > root.val) {
        return lowestCommonAncestor(root.right, p, q);
    }
    return root;
};



var lowestCommonAncestor = function(root, p, q) {
    // 先序遍历
    if(!root){
        return null
    }
    if(root===p||root===q){
        return root
    }
    let left=lowestCommonAncestor(root.left,p,q)
    let right=lowestCommonAncestor(root.right,p,q)
    if(left&&right){
        return root
    }
    return left?left:right
};




class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);
        if (root->val > max(p->val, q->val)) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else return root;
        }
        return NULL;
    }
};



class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node != target) {
            path.push_back(node);
            if (target->val < node->val) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_p[i] == path_q[i]) {
                ancestor = path_p[i];
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};
