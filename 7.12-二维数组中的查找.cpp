该数组 从左往右 依次递增
从上往下 依次递增
那我们取右上角的元素
判断 是否大于目标值，大于 则下面的一列元素都比目标值大被排除，列数--；
小于 则左边的一行元素都比元素小被排除，行数++；

代码

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)    return false;
        int m=0;
        int n=matrix[0].size()-1;
        
        while(m>=0&&m<matrix.size()&&n>=0&&n<matrix[0].size()){
            if(matrix[m][n]<target)
                m++;
            else if(matrix[m][n]>target)
                n--;
            else return true;
            
        }
        return false;
    }
};


