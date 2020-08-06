1.哈希set
当我们允许使用额外空间时，set是一个不错的选择。
我们可以遍历数组来将nums中的元素放入set；
如果nums[i] 已经存在于集合，则返回该值；
如果不存在，将该值添加到集合中。

C++

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set <int> hash_set;
        for (int i:nums)
        {
            if (hash_set.count(i) == 1)
                return i;
            else
                hash_set.insert(i);
        }
        return 0;
    }
};
复杂度分析
时间复杂度：O(N)。在最坏条件下，我们会遍历整个数组。
空间复杂度：O(N)。使用了哈希set作为辅助空间。
2.排序
排序是比较容易想到的方式。
排序后，相同的数会挨在一起，会改变原始数组，但不需要额外的储存空间。

C++

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i+1])
                return nums[i];
        }
        return 0;
    }
};
复杂度分析
时间复杂度：O(NlogN),sort排序。
空间复杂度：O(1)。
3.原地交换
本题条件，长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内，
因此我们可以将数组中的元素nums[i]与下标i进行匹配，
当出现相同数字，但下标不同的时候，说明出现的了重复
这种方法也对数组进行了修改

C++

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //遍历数组，将i与nums[i]对应起来
        for(int i = 0; i < nums.size(); ++i) {
            //如果当前值的下标不等于当前值,如 1 != nums[1]:2
            while(i != nums[i]) {
                //如果nums[1]:2 == nums[2]，找到相同数字，但下标不同，则说明出现重复数字
                if(nums[i] == nums[nums[i]])
                    //返回该数字
                    return nums[i];
                //若不相等
                else
                    //则交换nums[i]和nums[nums[i]]，一直循环交换
                    swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};
复杂度分析
时间复杂度：O(N),只对数组进行了一次变量。
空间复杂度：O(1)。
