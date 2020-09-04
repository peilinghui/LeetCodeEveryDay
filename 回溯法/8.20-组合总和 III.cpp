216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]


class Solution {
public:
    vector<vector<int>> ans;
    vector<int >cur;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n,1);
        return ans;
    }
    void dfs(int k,int sum,int r)//k记录次数，sum记录和，r用来确保数列里的数是递增的，确保不会有重复。
    {
        if(k==0&&sum==0)
        {
            ans.push_back(cur);
            return ;
        }
        if(k==0||sum<0)
            return;
        for(int i=r;i<=9;i++)
        {
           
            cur.push_back(i);
            dfs(k-1,sum-i,i+1);
            cur.pop_back();
        }
        return;
    }
   
};




class Solution {
public:
vector<int> candidates = { 1,2,3,4,5,6,7,8,9 };
vector<vector<int> > result;

void func(int k, int target, vector<int> &current, int index)
{
	if (k == 0 && target > 0 || target == 0 && k > 0)
		return;
	else if (k == 0 && target == 0)
	{
		result.push_back(current);
		return;
	}
	else
	{
		for (int i = index; i < candidates.size() && candidates[i] <= target; i++)
		{
			current.push_back(candidates[i]);
			func(k-1,target - candidates[i], current, i + 1);
			current.pop_back();
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	if (k == 1 && n <= 9)
		return { {n} };
	else if (n == 1 && k != 1)
		return {  };
	else
	{
		vector<int> current;
		func(k, n, current, 0);
	}
	return result;
}
};

