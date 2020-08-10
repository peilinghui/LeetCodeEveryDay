
深度优先遍历DFS：回溯法
递归

“回溯搜索”算法即“深度优先遍历 + 状态重置 + 剪枝”（这道题没有剪枝）

解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。
2、选择列表：也就是你当前可以做的选择。
3、结束条件：也就是到达决策树底层，无法再做选择的条件。

如果你不理解这三个词语的解释，没关系，我们后面会用「全排列」和「N 皇后问题」这两个经典的回溯算法问题来帮你理解这些词语是什么意思，现在你先留着印象。

代码方面，回溯算法的框架：

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择


递归到第几层：depth，已经选到了哪些数path，布尔数组used

class Solution {
private:
    vector<vector<int>>res;
    vector<bool>used;
    //s中存放前index个元素组合
    //向这个组合的末尾添加index+1个元素，获得一个有index+1个元素的组合
    void generatepermutation(vector<int>&nums,int index,vector<int>&s){
        if(index==nums.size()){   //递归终止条件
            res.push_back(s);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                s.push_back(nums[i]);//做选择
                used[i]=true;
                generatepermutation(nums,index+1,s);
                s.pop_back();   //撤销选择
                used[i]=false;
        }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used=vector<bool>(nums.size(),false);
        if(nums.size()==0)
            return res;
        vector<int>s;
        generatepermutation(nums,0,s);
        return res;
    }
};


class Solution {
public:
    void backtrack(vector<int>&nums, vector<vector<int>>& ans,int index){
        if(index==nums.size()) ans.push_back(nums);
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            backtrack(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        backtrack(nums,ans,0);
        return ans;
    }
};

全排列2：

class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> res;
        bt(a, res, 0);
        return res;
    }
    void bt(vector<int>& a, vector<vector<int>>& res, int level) {
        if (level == a.size()) {
            res.push_back(a);
            return;
        }
        //枚举的时候去重，只用没有排过的
        unordered_set<int> uniq;
        for (int i = level; i < a.size(); ++i) {
            if (uniq.count(a[i])) {
                continue; //already used
            }
            swap(a[i], a[level]);
            bt(a, res, level+1);
            swap(a[i], a[level]);
            uniq.insert(a[i]);
        }
    }
};




