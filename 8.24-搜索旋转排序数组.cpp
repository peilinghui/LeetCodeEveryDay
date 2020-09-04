搜索旋转排序数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4



二分模板：

 int left = 0, right = nums.size()-1,mid;
while(left < right){
       mid = (left + right)/2;
       if(nums[mid] >=target) right = mid;//修改if判断条件
       else left = mid + 1;
}



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) return -1;
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = (high + low) / 2;
            if (nums[mid] == target)
                return mid;
            if ((nums[mid] < target && target < nums[0]) || (nums[mid] < target && nums[mid] >= nums[0])
                    || (nums[mid] >= nums[0] && target < nums[0]))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                low = mid + 1;
            else
                high = mid;
        }
        return low == high && nums[low] == target ? low : -1;
    }
};

[0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 

nums[mid] < nums[0]，nums[0] > target，target > nums[mid]




class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};


81. 搜索旋转排序数组 II
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            while(left!=right && nums[left]==nums[right]) right--; //无重复值的解法中添加这行
            int mid = (left+right)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid] > target) {
                if(nums[mid] > nums[right] && target<nums[left]) left = mid +1;
                else right = mid-1;
            }else{
                if(nums[mid]<nums[left] && target>nums[right]) right = mid-1;
                else left = mid+1;
            }
        }
        return false;
    }
};

