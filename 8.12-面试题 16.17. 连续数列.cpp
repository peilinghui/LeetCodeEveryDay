给定一个整数数组，找出总和最大的连续数列，并返回总和。

示例：

输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。


动态规划
dp[i]代表dp[0:i]最大的连续数列和，求dp[i]我们有两种情况，要么选择nums[i] + dp[i-1], 要么直接选择nums[i];列入A[-1，1]，dp[0] = -1 即dp[1]选择 A[1] + dp[1]与A[1]中较大值，即状态转移方程
dp[i] = max(dp[i-1] + nums[i], nums[i])(也可以判断dp[i-1]是否为正数);


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];
        for(int i = 1 ; i < len;i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            sum = max(dp[i], sum);
        }
        return sum;
    }
};
时间复杂度O(N),空间复杂度O(N)；

动态规划
状态： dp[i]表示以i结尾的最大连续子序列
状态转移：
对于当前的nums[i]
如果nums[i-1] >= 0 dp[i-1] >= 0 则 dp[i] = dp[i-1] + nums[i];
否则 dp[i] = nums[i];

其实我们可以把nums当做dp数组，直接在原数组上面操作，这样可以省掉O(n)的空间


    // 动态规划
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return INT_MIN; 
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] >= 0)
                nums[i] += nums[i-1];
            maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
时间复杂度：O(N)
空间复杂度：O(1)



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int size = nums.size();
        int m = nums[0], sum = nums[0];
        for (int i = 1; i < size; ++i) {
            if (sum < 0) sum = nums[i];
            else sum += nums[i];
            m = max(m, sum);
        }
        return m;
    }
};
