class Solution {
public:
    int fib(int n) {
        int dp[101];
        dp[0]=0; dp[1]=1;
        
        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        
        return dp[n];
    }
};


等同于：
剑指 Offer 10- II. 青蛙跳台阶问题


class Solution {
public:
    int numWays(int n) {
        //动态规划4行解决
        //声明n+1大小的vector，+1是要存储0至n共n+1个数据。
        vector<int> v(n + 1, 1); 
        for(int i = 2; i <= n; i++)
            v[i] = (v[i - 1] + v[i - 2]) % 1000000007;//注意别忘记取余
        return v[n];//直接返回最后一个数，即最终结果
    }
};

class Solution {
public:
    int numWays(int n) {
        int dp[n+2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n+1; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }
        return dp[n+1];
    }
};

