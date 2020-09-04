 组合总和 Ⅳ


 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。



DFS暴力超时，只能用动态规划。

定义状态dp[i]为总和为i的所有可能的方法数。那么将所有方法按照最后一个数字进行分类，就可以得到状态转移方程了：

dp[i] = \sum_{j=0}^{n-1} dp[i - nums[j]] if i - nums[j] >= 0
dp[i]= 
j=0
∑
n−1
​	
 dp[i−nums[j]]ifi−nums[j]>=0

时间复杂度O(target * nums.size())O(target∗nums.size())
空间复杂度O(target)O(target)


class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i ++){
            for(int j = 0; j < nums.size(); j ++){
                if(i - nums[j] >= 0) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};



ans[target]=ans[target−current]+count
其中current表示target之中的状态，count表示总和恰好为current时有多少种方案。


//超时代码
class Solution {
public:
    int count;
    int combinationSum4(vector<int>& candidates, int target) {
        dfs(target,target,candidates);
        return count;
    }
    void dfs(int target,int remain,vector<int>& candidates){
        if(remain<0)return;
        if(remain==0){
            count++;
            return;
        }
        for(int i = 0;i<candidates.size();i++){
            dfs(target,remain - candidates[i],candidates);
        }
    }
};


//加了记忆化的代码
class Solution {
public:
    vector<long long> temp;
    long long count;
    int combinationSum4(vector<int>& candidates, int target) {
        temp = vector(target+1,-1ll);
        for(int i=1;i<=target;i++){
            count=0;
            dfs(i,i,candidates);
            temp[i]=count;
        }
        return count;
    }
    void dfs(int target,int remain,vector<int>& candidates){
        if(remain<0)return;
        if(temp[remain]!=-1){//如果还要凑的数已经算过了则加上当前方案数之和返回即可。
            count+=temp[remain];
            count%=INT_MAX;//防止超出整数的表示范围
            return;
        }
        if(remain==0){
            count++;
            return;
        }
        for(int i = 0;i<candidates.size();i++){
            dfs(target,remain - candidates[i],candidates);
        }
    }
};
