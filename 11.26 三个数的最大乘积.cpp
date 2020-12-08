628. 三个数的最大乘积
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。



class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max,temp,len;
        len = nums.size() - 1;
        temp = nums[len] * nums[len - 1] * nums[len - 2];
        max = nums[0] * nums[1] * nums[len];
        return temp > max ? temp : max;
    }
};


先排序 从小到大
分情况讨论：
(1) 全正，最大值在最后3个
(2) 全负，最大值在最后3个
(3) 有正有负:最大值一定是两负一正，最大值在最后1位和前2个
故最大值只会存在于这两种情况中。
代码

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();

        return max(nums[0]*nums[1]*nums[len-1] ,nums[len-1]*nums[len-2]*nums[len-3] );
    }
};
