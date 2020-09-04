

78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


class Solution {
    int n;
    vector<vector<int>> ans;
public:

    void backtrack(int first,vector<int>& nums,int num,vector<int>& path)
    {//num是，这一轮要求的子集的规模
        if(path.size()==num)
        {
            ans.push_back(path);
        }
        for(int i=first;i<n;i++)
        {//如果path没满，再从first之后的某个位置，添加一个元素
            path.push_back(nums[i]);
            backtrack(i+1,nums,num,path);//注意，这里放i+1,作用是，保证一个path里面的元素的
                                            //顺序，在原来nums里面的对应顺序是一样的。自动起到
                                            //去重的功能。
            path.pop_back();//准备迎接下一个候选nums[i]。
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        n=nums.size();
        //枚举元素数目i
        for(int i=0;i<=n;i++)
        {
            vector<int> path;//空的
            backtrack(0,nums,i,path);
        }

        return ans;
        }
    };
    

90. 子集 II
给定一个**可能包含重复元素***的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]






    
  