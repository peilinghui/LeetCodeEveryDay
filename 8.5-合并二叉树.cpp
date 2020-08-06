

队列迭代：
层次遍历的思想：
1.每次从两个树中各取一个节点（记为node1, node2）入队;
2.出队时将两个节点值相加，并判断node1和node2的左子树是否为空，若两个左子树都不空，直接入队；若有一个为空，新建一个val为0的节点，然后入队；若两个的左子树都为空，pass。右子树的判断同理。


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL || t2==NULL) return t1==NULL?t2:t1;
        queue<TreeNode *>q;
        q.push(t1); q.push(t2);
        while(!q.empty()){
            TreeNode *t1 = q.front(); q.pop();
            TreeNode *t2 = q.front(); q.pop();
            t1->val +=t2->val;
            if(t1->left!=NULL && t2->left!=NULL){
                q.push(t1->left); q.push(t2->left);
            }else if(t1->left==NULL){
                t1->left = t2->left;
            }
            if(t1->right!=NULL && t2->right!=NULL){
                q.push(t1->right); q.push(t2->right);
            }else if(t1->right==NULL){
                t1->right = t2->right;
            }
        }
        return t1;
    }
};


class Solution { // iterative: Queue    
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        if(!t1 || !t2) return t1? t1:t2;

        queue<TreeNode*> q1,q2;
        q1.push(t1);
        q2.push(t2);
        
        while(!q1.empty() && !q2.empty()){
            TreeNode* c1(q1.front());
            TreeNode* c2(q2.front());
            q1.pop();
            q2.pop();
            
            c1->val+=c2->val;
            
            if(!c1->left && c2->left) c1->left = c2->left;
            else if(c1->left && c2->left) { q1.push(c1->left); q2.push(c2->left); }
            
            if(!c1->right && c2->right) c1->right = c2->right;
            else if(c1->right && c2->right) { q1.push(c1->right); q2.push(c2->right); }
        }
        return t1;
    }
};



栈迭代：

class Solution { // iterative: Stack
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        if(!t1 || !t2) return t1? t1:t2;
                
        stack<TreeNode*> s1,s2;
        s1.push(t1);
        s2.push(t2);
        
        while(!s1.empty()){
            TreeNode* c1(s1.top());
            TreeNode* c2(s2.top());
            s1.pop();
            s2.pop();
            
            c1->val+=c2->val;
            
            if(!c1->left && c2->left) c1->left = c2->left;
            else if(c1->left && c2->left) { s1.push(c1->left); s2.push(c2->left); }
            
            if(!c1->right && c2->right) c1->right = c2->right;
            else if(c1->right && c2->right) { s1.push(c1->right); s2.push(c2->right); }
        }
        return t1;
    }
};



make_pair的用法：
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(t1, t2));
        while(q.size()) {
            pair<TreeNode*,TreeNode*> cur = q.front(); 
            q.pop();
            cur.first->val = cur.first->val + cur.second->val;
            if(cur.second->left) {
                if(!cur.first->left){
                    cur.first->left = new TreeNode(0);
                }
                q.push(make_pair(cur.first->left, cur.second->left));
            }
            if(cur.second->right) {
                if(!cur.first->right ){
                    cur.first->right = new TreeNode(0);
                }
                q.push(make_pair(cur.first->right, cur.second->right));
            }
        }
        return t1;
    }
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        stack<pair<TreeNode*, TreeNode*>> stk;
        if(t1 && t2) stk.push(make_pair(t1, t2));
        while(stk.size()) {
            pair<TreeNode*,TreeNode*> cur = stk.top(); stk.pop();
            cur.first->val = cur.first->val + cur.second->val;
            if(cur.second->left) {
                if(!cur.first->left) cur.first->left = new TreeNode(0); //如果左子树不存在，新建值为0的节点
                stk.push(make_pair(cur.first->left, cur.second->left));
            }
            if(cur.second->right) {
                if(!cur.first->right ) cur.first->right = new TreeNode(0); //如果右子树不存在，新建值为0的节点
                stk.push(make_pair(cur.first->right, cur.second->right));
            }
        }
        return t1;
    }
};


递归：

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(!t1)
            return t2;
        if(!t2)
            return t1; 
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
