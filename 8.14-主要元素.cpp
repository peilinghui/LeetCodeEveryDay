解题思路
方法一：map，此方法时间复杂度O(n)，空间复杂度O(n)
方法二：排序+双指针，此方法时间复杂度O(nlog2n)，空间复杂度O(1)
方法三：投票法，

代码
map：

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i : nums) {
            map[i] ++;
            if(map[i] > nums.size() / 2) return i;
        }
        return -1;
    }
};


排序+双指针：

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; j < nums.size(); i = j) {
            while(j < nums.size() && nums[i] == nums[j]) j ++;
            if(j - i > nums.size() / 2) return nums[i];
        }
        return -1;
    }
};
