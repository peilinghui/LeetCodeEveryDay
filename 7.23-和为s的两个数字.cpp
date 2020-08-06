思路描述：可以用hash表存一下每个数字，其实找到两个数字之和 a+b = target，就相当于找到是否存在 target - b 这个数字。时间复杂度和空间复杂度均为 O(n)。


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        for(int i = 0; i < nums.size(); i ++){
            numbers[nums[i]] = 1;
        }
        for(int i = 0; i < nums.size(); i ++){
            if(numbers[target - nums[i]]) 
                return {nums[i], target - nums[i]};
        }
        return {};
    }
};
因为数组递增，所以可以使用双指针法，首先两个指针指向首尾，和如果大于target，右指针左移，小于target，左指针右移。时间复杂度为 O(n)，空间复杂度 O(1)。

为什么和如果大于target，右指针左移呢？因为目前的 nums[i] + nums[j] > target，那么 i 右边的任意一个数字 + nums[j] > target， 所以右指针不左移就不可能找到解。

相应的如果 nums[i] + nums[j] < target，那么 i 左边的任意一个数字 + nums[j] < target， 所以左指针不右移就不可能找到解。


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] > target) j --;
            else if(nums[i] + nums[j] < target) i ++;
            else return {nums[i], nums[j]};
        }
        return {};
    }
};




class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  // 双指针
        vector<int> result;
        int sum, i = 0, j = nums.size()-1;
        while(i < j){
            sum = nums[i]+nums[j];
            if(sum==target){
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                break;
            }
            if(sum>target) j--;
            else i++;
        }
        
        return result;
    }
};

