1588. 所有奇数长度子数组的和
给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。

 

示例 1：

输入：arr = [1,4,2,5,3]
输出：58
解释：所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
示例 2：

输入：arr = [1,2]
输出：3
解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
示例 3：

输入：arr = [10,11,12]
输出：66


因为原数组是有序的，但是包含负数
如果负数存在，按照原来顺序平方之后的数组，两头大，中间小
直观的想法是先找到平方最小的数，即最接近 0 的数，再向两侧展开
但是这样就还需要先找 0 ，不如从两侧向中心逼近，最后再将数组逆序
所以，根据绝对值大小来判断，使用双指针从两端向中心靠拢，得到平方数组之后逆序
也可以优化一下，先申请相同长度的数组，再从后面往前依次填入


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for (int i = 0, j = A.size() - 1; i <= j; i++) {
            while (i < j && abs(A[i]) < abs(A[j])) {
                ans.push_back(A[j] * A[j]);
                j--;
            }
            ans.push_back(A[i] * A[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size(), 0);
        int k = A.size() - 1;
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (abs(A[i]) < abs(A[j])) {
                ans[k--] = A[j] * A[j];
                j--;
            }
            else {
                ans[k--] = A[i] * A[i];
                i++;
            }
        }
        return ans;
    }
};



双指针，从后往前填充 res 数组。先放C++代码，思路简单易懂。

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        if(len == 1){
            return {A[0] * A[0]};
        }
        
        vector<int>res(len);
        int i = 0, j = len - 1;
        for(int pos = len - 1; pos >= 0; --pos){
            if(abs(A[i]) > abs(A[j])){
                res[pos] = A[i] * A[i];
                ++ i;
            }
            else{
                res[pos] = A[j] * A[j];
                -- j;
            }
        }
        return res;
    }
};

方法三：双指针
思路与算法

同样地，我们可以使用两个指针分别指向位置 00 和 n-1n−1，每次比较两个指针对应的数，选择较大的那个逆序放入答案并移动指针。这种方法无需处理某一指针移动至边界的情况，读者可以仔细思考其精髓所在。

代码

C++JavaPython3GolangC

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (A[i] * A[i] > A[j] * A[j]) {
                ans[pos] = A[i] * A[i];
                ++i;
            }
            else {
                ans[pos] = A[j] * A[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};

