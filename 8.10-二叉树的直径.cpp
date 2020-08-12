
很容易想到求直径就是求左右两边最大的边的长度加起来，这个明显是一个递归可解决的问题
而返回值只能取一个，要么是最大长度 要么是最大直径 所以写起来最快的方式我们需要把其中一个值放到全局

我们在递归的时候只是返回当前节点的最大深度，即左右子节点的最大深度+1
然后每次都顺便更新一下最大直径，如果以当前节点为根节点的最大直径更大的话。




class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) return 0; // 访问到空节点了，返回0
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};





在求树的深度的过程中，保存左右子深度之和的最大值
class Solution {
public:
    int length = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return length;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        int lret = depth(root->left);
        int rret = depth(root->right);
        length = max(length, lret+rret);
        return max(lret, rret) + 1;
    }
};
