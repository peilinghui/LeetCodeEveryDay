class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root -> val - p->val)*(root -> val - q ->val) <= 0 ){
            return root;
        }
        if(root -> val > p -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        if(root -> val < p -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }
        return NULL;
    }
};


那么边界条件就是，p、q 分别在 root 的两边，或者 p、q 等于 root，那么 root 就是 p、q 的公共祖先
当 p、q 都小于 root，根据第一点说的特征，那么 p、q 的祖先一定在 root 的左子树上，所以接下来遍历左子树就行
同理，当 p、q 都小于 root，只需要遍历 root 的右子树即可




class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || (root->left == NULL && root->right == NULL))return NULL;
        while(root) {
            if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val) || root->val == p->val || root->val == q->val) return root;

            if(root->val > p->val && root->val > q->val) root = root->left;
            if(root->val < p->val && root->val < q->val) root = root->right;
        }
        return root;
    }
};

