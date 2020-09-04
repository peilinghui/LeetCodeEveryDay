给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]

class Solution {
    vector<int> nums;
    vector<vector<int>> ans;
    vector<int> a;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        this->nums = move(nums);
        dfs(0, target);
        return ans;
    }

    void dfs(int l, int target) {
        if (target == 0) {
            ans.push_back(a);
            return;
        }

        for (int i = l; i < nums.size(); ++i) {
            if (target - nums[i] < 0) break; //剪枝
            a.push_back(nums[i]);
            dfs(i, target - nums[i]);
            a.pop_back();
        }
    }
};


class Solution {
    vector<int> nums;
    vector<vector<int>> ans;
    vector<int> a;
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        this->nums = move(nums);
        dfs(0, target);
        return ans;
    }

    void dfs(int l, int target) {
        if (target == 0) {
            ans.push_back(a);
            return;
        }

        for (int i = l; i < nums.size(); ++i) {
            if (target - nums[i] < 0) break; //剪枝1
            if (i > l && nums[i] == nums[i - 1]) continue; //剪枝2
            a.push_back(nums[i]);
            dfs(i + 1, target - nums[i]);
            a.pop_back();
        }
    }
};

