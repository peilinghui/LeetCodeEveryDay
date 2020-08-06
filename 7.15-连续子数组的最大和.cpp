思路描述：

这个可以使用一个动态规划的思路，用 dp[i] 表示以 nums[i] 结尾的最大和
那么可以得出递推表达式 dp[i] = max(dp[i - 1] + nums[i], nums[i])
因为如果以 nums[i - 1] 结尾的最大和加上 nums[i] 的值小于 nums[i] 的值，
那么以 nums[i] 结尾的最大和肯定是 nums[i] 了。


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), nums[0]);
        int ans = dp[0];
        for(int i = 1; i < nums.size(); i ++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

一般动态规划空间复杂度都是可以进行优化的，我们这个也是可以优化的，
因为我们每次其实都是只用到了 dp[i - 1] 去更新 dp[i]，那么我们直接使用一个变量去替换就好了。


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int ans = dp;
        for(int i = 1; i < nums.size(); i ++){
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
    }
};


我们在原地修改数组，将数组每个位置的值更改为当前位置上的最大和。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxnum = nums[0];
        for (int i = 1;i< nums.size();++i){
            if (nums[i - 1] > 0){
                nums[i] += nums[i - 1];
            }
            maxnum = max(maxnum,nums[i]);
        }
        return maxnum;
    }
};






class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();

        if(size == 0) return INT_MIN;
        else if(size == 1) return nums[0];

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        int result = nums[0];

        for(int i=1;i<size;++i)
        {
            dp[i] = dp[i-1]>0 ? (nums[i]+dp[i-1]) : nums[i];

            if(dp[i] > result) result = dp[i];
        }

        return result;
    }
};
