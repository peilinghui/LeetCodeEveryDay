
辅助函数height获得节点高度

主函数isBalance验证二叉树
//isBalanced(root->left)&&isBalanced(root->right);
递归终止条件为：
1.节点为空，表示全部满足条件 是平衡二叉树 为true
2.节点左右子树高度差大于1，此时已经不是平衡树，返回false



class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};



class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};


class Solution {
public:
    // 返回以该节点为根节点的二叉树的高度，如果不是二叉搜索树了则返回-1
    int depth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = depth(node->left);
        if (leftDepth == -1) return -1; // 说明左子树已经不是二叉平衡树
        int rightDepth = depth(node->right);
        if (rightDepth == -1) return -1; // 说明右子树已经不是二叉平衡树
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) == -1 ? false : true; 
    }
};




class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return max(height(root->left), height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL) return true;
        else return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);//这里要求左右子树的高度差不超过1，并且左右子树都是平衡树
    }
};


class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(height(root->left)-height(root->right))>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
