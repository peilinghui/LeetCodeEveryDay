
491. 递增子序列
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]




class Solution {
private:
void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subseq, int startIndex) {
    if (subseq.size() > 1) {
        result.push_back(subseq);
        // 注意这里不要加return，因为要取所有的可能
    }
    unordered_set<int> uset; // 使用set来对尾部元素进行去重
    for (int i = startIndex; i < nums.size(); i++) {
        if ((subseq.empty() || nums[i] >= subseq.back())
                && uset.find(nums[i]) == uset.end()) {
            subseq.push_back(nums[i]);
            backtracking(nums, result, subseq, i + 1);
            subseq.pop_back();
            uset.insert(nums[i]);//在回溯的时候，记录这个元素用过了，后面不能再用了
        }
    }
}
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subseq;
        backtracking(nums, result, subseq, 0);
        return result;
    }
};


方法一
子序列
数组的子序列，需要保证元素的相对位置关系和原数组中保存一致，因此需要遍历数组从头到尾挑选元素，挑选的每一步可以有要、或者不要当前元素两种选择；
所有挑选情况的排列组合即为所有的子序列，判断满足条件的子序列放入结果即可。
对当前所有可能的选择进行遍历，即：深度优先搜索算法。


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       
        set<vector<int>> st;//用 set 保存结果去重复
        vector<int> cur;//当前子序列
        dfs(st,cur,nums,0);
        vector<vector<int>> res(st.begin(),st.end());  
        return res;
        
    }

    void dfs(set<vector<int>> &st, vector<int> &cur,vector<int>& nums,int curIndex )
    {
        if( curIndex >= nums.size() ) //超边界，没元素可选
        {
            //判断当前子序列
            if( cur.size() > 1)
                st.insert(cur);
            return;
        }
        
        //遍历当前所有可能的选择：选择curIndex 、不选curIndex
        //选择curIndex
        if( cur.size() == 0 || nums[curIndex] >= cur.back())
        {
            cur.push_back(nums[curIndex]);//可以加入序列
            dfs( st,cur,nums,curIndex+1);
            cur.pop_back();//撤销选择
        }
        //不选curIndex
        dfs( st,cur,nums,curIndex+1);
    }
       
};
方法二
去重优化：新加入的元素只能在当前子序列的最后一个元素对应的下标之后的位置进行挑选，
若将要添加的元素值在该位置之后是第一次出现的，则不重复


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       
        vector<vector<int>> res;  
        vector<int> cur;//当前子序列
        dfs(res,cur,nums,0,-1);  
        return res;
        
    }
    //判断重复：要添加的元素值不是第一次出现即可
    //                                当前子序列末尾元素  要添加的元素
    bool checkCanAdd(vector<int>& nums,int  lastIndex,int curIndex)
    {
        for(int i = lastIndex+1;i < curIndex;++i)
        {
            if( nums[i] == nums[curIndex])
                return false;
        }
        return true;
    }
    void dfs( vector<vector<int>> &res, vector<int> &cur,vector<int>& nums,int curIndex ,int lastIndex)
    {
        if( curIndex >= nums.size() ) //超边界，没元素可选
        {
            //判断当前子序列
            if( cur.size() > 1)
                res.push_back(cur);
            return;
        }
        
        //遍历当前所有可能的选择：选择curIndex 、不选curIndex
        //选择curIndex
        if( cur.size() == 0 || nums[curIndex] >= cur.back())
        {
            if( checkCanAdd(nums,lastIndex,curIndex))//非重复
            {
                cur.push_back(nums[curIndex]);//可以加入序列
                dfs( res,cur,nums,curIndex+1,curIndex);
                cur.pop_back();//撤销选择
            }
        }
        //不选curIndex
        dfs( res,cur,nums,curIndex+1,lastIndex);
    }    
};




class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solver(nums, 0);
        return res;
    }

    void solver(vector<int>& nums, int i){
        if(tmp.size() > 1) res.push_back(tmp);
        unordered_set<int> used;
        for(int j = i; j < nums.size(); j++){
            int v = nums[j];
            if(used.find(v) != used.end()) continue;
            else{
                if(tmp.size() == 0 || v >= tmp.back()){
                    used.insert(v);
                    tmp.push_back(v);
                    solver(nums, j+1);
                    tmp.pop_back();
                }
            }
        }
    }
    
};

