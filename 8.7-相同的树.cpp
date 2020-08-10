class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){//是否两个都是空
            return true;
        }
        if(p!=nullptr && q!=nullptr && p->val==q->val){//非空，且值相等
                return isSameTree(p->left, q->left)&&isSameTree(p->right,q->right);//与操作是精髓
        }else{
            return false;
        }
    }
};



二叉树算法的设计的总路线：明确一个节点要做的事情，然后剩下的事抛给框架。


void traverse(TreeNode root) {
    // root 需要做什么？在这做。
    // 其他的不用 root 操心，抛给框架
    traverse(root.left);
    traverse(root.right);
}

1. 如何把二叉树所有的节点中的值加一？


void plusOne(TreeNode root) {
    if (root == null) return;
    root.val += 1;

    plusOne(root.left);
    plusOne(root.right);
}
2. 如何判断两棵二叉树是否完全相同？


boolean isSameTree(TreeNode root1, TreeNode root2) {
    // 都为空的话，显然相同
    if (root1 == null && root2 == null) return true;
    // 一个为空，一个非空，显然不同
    if (root1 == null || root2 == null) return false;
    // 两个都非空，但 val 不一样也不行
    if (root1.val != root2.val) return false;

    // root1 和 root2 该比的都比完了
    return isSameTree(root1.left, root2.left)
        && isSameTree(root1.right, root2.right);
}

