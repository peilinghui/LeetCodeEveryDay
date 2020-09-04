102.二叉树的层次遍历
ps:这道题其实就是102.二叉树的层次遍历的翻版，
多了一个条件if(level %2==0),层数level从0开始表示二叉树的第一行，
如果为偶数行则顺序加入，如果为奇数行则将数字每次插入到最前面

103. 二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]


DFS:

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root,0);
        return res;
    }
     void dfs(TreeNode* root,int level){
        if(!root) return;
        if(level == res.size()) res.resize(level+1);
        if(level%2==0){//奇数
            res[level].push_back(root->val);
        }else{
          res[level].insert(res[level].begin(),root->val);  
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
};



class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == NULL)   return {};  
        queue<TreeNode*> q;     
        q.push(root);  

        int level=0;
        while (!q.empty()) 
        {  
            vector<int>temp;                //存放每一层的元素值
            int count=q.size();             //队列大小表示当前层数的元素个数
            while(count--)                  //count--逐个对该层元素进行处理
            {
            TreeNode *t=q.front();             q.pop();    
            if(level%2 ==0) 
            temp.push_back(t->val);
            else
            temp.insert(temp.begin(),t->val);
            if(t->left)     q.push(t->left);
            if(t->right)    q.push(t->right);
            }

            level++;
            res.push_back(temp);           //将当层元素的vector加入res中
        }
        return res;
        }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)   return {};  
        queue<TreeNode*> q;     
        q.push(root);  

        int level=0;
        while (!q.empty()) {  
            vector<int>temp;                //存放每一层的元素值
            int count=q.size();             //队列大小表示当前层数的元素个数
            for(int i=0;i<count;i++){               //count--逐个对该层元素进行处理
                TreeNode *t=q.front();   q.pop();    
                if(level%2 ==0) temp.push_back(t->val);
                else  temp.insert(temp.begin(),t->val);
                if(t->left)     q.push(t->left);
                if(t->right)    q.push(t->right);
            }
            level++;
            res.push_back(temp);           //将当层元素的vector加入res中
        }
        return res;
    }
};
