

首先判断存在空数组的情况；
在两个数组均非空的情况下，判断最终合并数组的长度m+n，从后往前排入数组；
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int cur = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[cur] = A[i];
                i--;
                cur--;
            }
            else{
                A[cur] = B[j];
                j--;
                cur--;
            }
        }
        while(i >= 0){
            A[cur] = A[i];
            cur--;
            i--;
        }
        while(j >= 0){
            A[cur] = B[j];
            cur--;
            j--;
        }
    
    }
};


class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(A.empty() || B.empty()) A = A.empty()?B:A;

        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        for(k = m+n-1; k >= 0; k--){
            if(i>-1 && j>-1)
                A[k] = ((A[i]>=B[j])?A[i--]:B[j--]);
            else if(i == -1)
                A[k] = B[j--];
            else if(j == -1)
                A[k] = A[i--];
        }
    }
};




基于归并排序的归并思想，采用双指针对两数组同时进行比较并将小的元素放入临时数组中，然后将其中一个数组多余的部分直接塞入临时数组中，此时的到的就是归并好的数组。
时间复杂度为O（m+n），空间复杂度为O（m+n）


class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int* temp = new int[m+n];
        int i = 0 ; 
        int j=0;
        int k = 0;
        while (i < m && j < n)
        {
            if (A[i] <= B[j])
                temp[k++] = A[i++];
            else
                temp[k++] = B[j++];
        }
        while(i <m)
            temp[k++] = A[i++];
        while(j < n)
            temp[k++] = B[j++];
        for (int s = 0; s <m+n; s++)
            A[s] = temp[s];
        delete []temp;
    }
};


