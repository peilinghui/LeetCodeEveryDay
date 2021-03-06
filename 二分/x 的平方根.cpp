x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2



class Solution {
public:
    int mySqrt(int x) {
        //注：在中间过程计算平方的时候可能出现溢出，所以用long long。
        long long i=0;
        long long j=x/2+1;//对于一个非负数n，它的平方根不会大于（n/2+1）
        while(i<=j)
        {
            long long mid=(i+j)/2;
            long long res=mid*mid;
            if(res==x) return mid;
            else if(res<x) i=mid+1;
            else j=mid-1;
        }
        return j;
    }
};

