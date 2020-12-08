
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1



//时间复杂度：O(logN)，这里N是数组的长度，每一次都将问题的规模缩减为原来的一半，因此时间复杂度是对数级别的；
//空间复杂度：O(1)，使用到常数个临时变量。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return 0;
        //如果在数组的末尾，插入位置的下标就是数组的长度；
        if(nums[size -1]<target) return size;

        int left = 0;int right = size-1;
        while(left<right){
            int mid = left + (right - left)/2;
            // 严格小于 target 的元素一定不是解
            if(nums[mid] < target){
                // 下一轮搜索区间是 [mid + 1, right]
                left = mid +1;
            }else{
                // 下一轮搜索区间是 [left, mid] 
                right = mid;
            }
        }
        return left;   
    }
};