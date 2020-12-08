867. 转置矩阵
给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

 

示例 1：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]


创建新数组存储返回值，ij互换位置即可

代码：


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ans;
        int row = A.size();
        int col = A[0].size();
        for(int j = 0 ; j < col ; j++) {
            vector<int> v;
            for(int i = 0 ; i < row ; i++)
                v.push_back(A[i][j]);
            ans.push_back(v);
        }
        return ans;
    }
};

如何声明一个m*n 的矩阵是需要记忆的。
vector<vector<int>> A(m,vector<int>(n,0));

代码

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int> > result( A[0].size(),vector<int>(A.size(),0));
        for(int i = 0 ; i< A.size(); i++)
        {
            for (int j = 0; j <A[0].size();j++)
            {
                result[j][i] = A[i][j];
            }
        }
        return result;

    }
};


先遍历列，再遍历行。

c++

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> B(cols, vector<int>(rows, 0));
        for(int i  = 0;i < cols; ++i){
            for(int j = 0;j < rows; ++j){
                B[i][j] = A[j][i];
            }  
        }
        return B;
    } 
};


