1. 一次遍历
最普通最简单的想法，从头开始遍历数组，遇到i == nums[i]的情况，直接return i

时间复杂度为O(n)，空间复杂度为O(1)

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        // 1. 一次遍历
        for(int i = 0; i<nums.size(); ++i){
            if(i == nums[i]) return i;
        }
        return -1;
    }
};

二分查找
二分查找也称折半查找，它是一种效率较高的查找方法；使用二分查找要求线性表必须采用顺序存储结构，而且表中元素按关键字有序排列。

基本原理
①．查找
因为序列已经单调且有序排列，从中间位置开始比较，一次可以排除一半的数据，不断缩小查找范围。
②．终止条件
找到了目标值，或者左右边界已经构不成有效区间。
③．本质思想
本质也是分治思想的应用，就是通过二分后，可以根据已知信息来排除一半数据，进而缩小问题规模在更小的区间内进行查找。

题目分析
由于数组中元素可能重复，二分后仅根据 mid 的值无法判断应该进入左区间还是右区间，因此只能按照左、中、右的顺序依次对三个区间进行查找。


代码

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        
       return findMagicIndex( nums,0 ,nums.size()-1);
    }
    int  findMagicIndex(vector<int>& nums,int left ,int right )
    {
        int res = -1;
        if(left <= right )
        {
            int mid = left + (right - left )/2;
            res = findMagicIndex(nums,left,mid-1);
            if( res != -1)
                return res;
            if( nums[mid] == mid)
                return mid;
            return  findMagicIndex(nums,mid+1,right);
        }
        return res;
    }
};
