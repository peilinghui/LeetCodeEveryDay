class Solution {
    //两个错误节点，一个前驱节点
    TreeNode *x=nullptr, *y=nullptr, *pred = nullptr;
    void inorder(TreeNode* node){
        if(node == nullptr) return;
        inorder(node->left);
        if(pred != nullptr && node->val < pred->val){
            y=node;
            if(x==nullptr) x= pred;
            else return;
        }
        pred = node;
        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};



class Solution {
    int x=-1,y=-1;
    void  inorder(TreeNode* node,vector<int>& nums){
        if(node == nullptr) return;
        inorder(node->left,nums);
        nums.push_back(node->val);
        inorder(node->right,nums);
    }
    void findTwoSwappedNums(vector<int>& nums){
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]>nums[i+1]){
                y = nums[i+1];
                if(x==-1) x=nums[i];
                else break;
            }
        }
    }
    void recover(TreeNode* node){
        if(node == nullptr) return;
        if(node->val == x) node->val = y;
        else if(node->val == y){
            node->val = x;
        }
        recover(node->left);
        recover(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int>nums{};
        inorder(root,nums);//中序遍历
        findTwoSwappedNums(nums);//找到两个数交换
        recover(root);//恢复树
    }
};