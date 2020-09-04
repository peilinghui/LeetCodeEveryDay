
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4



二分查找：

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
9 出现在 nums 中并且下标为 4

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1; // 注意

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid; 
            else if (nums[mid] < target)
                left = mid + 1; // 注意
            else if (nums[mid] > target)
                right = mid - 1; // 注意
        }
        return -1;

    }
};









一、寻找一个数（基本的二分搜索）
这个场景是最简单的，肯能也是大家最熟悉的，即搜索一个数，如果存在，返回其索引，否则返回 -1。


int binarySearch(int[] nums, int target) {
    int left = 0; 
    int right = nums.size() - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}


二、寻找左侧边界的二分搜索
以下是最常见的代码形式，其中的标记是需要注意的细节：


int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}



三、寻找右侧边界的二分查找
类似寻找左侧边界的算法，这里也会提供两种写法，还是先写常见的左闭右开的写法，只有两处和搜索左侧边界不同，已标注：


int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 注意
}

int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;
        }
    }
    // 这里改为检查 right 越界的情况，见下图
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}



class Solution {
private:
    int findFitstPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    int findLastPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;

            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }


public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        int fitstPosition = findFitstPosition(nums, target);

        if (fitstPosition == -1) {
            return {-1, -1};
        }
        int lastPosition = findLastPosition(nums, target);
        return {fitstPosition, lastPosition};
    }
};


