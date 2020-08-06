120. 三角形最小路径和（DP自上到下、自下到上+优化）
萱萱
发布于 11 小时前
579
1、DP自上到下——二维数组

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; ++i) 
        {
            // 每一行最左侧的元素
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            // 每一行最右侧的元素
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
2、DP自上到下——一维数组

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // 一维数组dp记录遍历到每一行的每个节点的最小路径和
        vector<int> dp(n);
        // 初始化
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++)
        {
            // 每一行最右侧的元素
            dp[i] = dp[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--)
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            // 每一行最左侧的元素
            dp[0] += triangle[i][0];
        }
        // 返回dp的最小值
        return *min_element(dp.begin(), dp.end());
    }
};
3、DP自下到上——二维数组（原地）

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 行数
        int n = triangle.size();
        // 从倒数第二行开始
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }   
        return triangle[0][0];
    }
};
4、DP自下到上——一维数组

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // 一维数组dp记录遍历到每一行的每个节点的最小路径和
        vector<int> dp(n + 1, 0);  
        
        // 从最后一行开始依次更新每一行的dp值
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j< triangle[i].size(); j++)
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);

        return dp[0];
    }
};