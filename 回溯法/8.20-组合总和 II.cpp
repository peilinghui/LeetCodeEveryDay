给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


class Solution {
    vector<int> nums;
    vector<vector<int>> ans;
    vector<int>a;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->nums = move(candidates);
        dfs(0,target);
        return ans;
    }

    void dfs(int l,int target){
        if(target == 0){
            ans.push_back(a);
            return;
        }
        for(int i=l;i<nums.size();++i){
            if(target - nums[i] <0) break;
            if(i>l && nums[i]==nums[i-1]) continue;
            a.push_back(nums[i]);
            dfs(i+1,target-nums[i]);
            a.pop_back();
        } 
    }
};
