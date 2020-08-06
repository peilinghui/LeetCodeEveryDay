
解题思路
通过 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]B[i]=A[0]×A[1]×…×A[i−1]×A[i+1]×…×A[n−1] ，我们发现 B[i]B[i] 就是 A[i]A[i] 左边所有元素的积 乘 A[i]A[i] 右边所有元素的积。

这和分发糖果的操作思想一样，都是利用对称关系，经过两遍对称运算就能得到最终的结果。

对称遍历
从左往右遍历累乘，结果保存在数组 retret 中，此时 ret[i]ret[i] 表示，A[i]A[i] 左边所有元素的乘积
然后从右往左遍历累乘，获取A[i]A[i] 右边所有元素的乘积
两边遍历之后得到的 retret，就是最终结果
代码

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ret(n, 1);
        int left = 1;
        for (int i = 0; i < n; i ++) {
            ret[i] = left;
            left = left * a[i];
        } 
        int right = 1;
        for (int i = n-1; i >= 0; i --) {
            ret[i] *= right;
            right *= a[i];
        }
        return ret;
    }
};




class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> L (n, 1);
        vector<int> R (n, 1);
        for(int i = 1; i < n; i++)
            L[i] = L[i - 1] * a[i - 1];
        for(int j = n - 2; j > -1; j--)
            R[j] = R[j + 1] * a[j + 1];
        for(int i = 0; i < n; i++)
            L[i] = L[i] * R[i];
        return L;
    }
};



class Solution {
    public int[] constructArr(int[] a) {
        if(0==a.length) {
            return new int[0];
        }
        int length=a.length;
        int[] b=new int[length];
        b[0]=1;
        for(int i=1;i<length;i++) {
            b[i]=b[i-1]*a[i-1];
        }
        int temp=1;
        for(int j=length-2;j>=0;j--) {
            temp*=a[j+1];
            b[j]*=temp;
        }
        return b;
    }
}

