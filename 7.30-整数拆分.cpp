
方法一：动态规划

class Solution {
public:
    int integerBreak(int n) {
        vector <int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};


class Solution {
public:
    unordered_map<int,int> mp;
    int integerBreak(int n) {
        mp[1] = 1;
        mp[2] = 1;
        return dp(n);
        
        
    }
    int dp(int n)
    {
        int res = 0;
        if( mp.find(n) != mp.end())
        {
            return mp[n];
        }
        for(int i = 1;i < n;i++)
        {
            int temp = max(i*(n-i),i*dp(n-i));
            res = max(res,temp);
        }
        mp[n] = res;
        return res;
    }
};

