快指针：遍历整个数组；
慢指针：记录可以覆写数据的位置；
题目中规定每个元素最多出现两次，因此，应检查快指针指向的元素和慢指针指针所指向单元的前一个元素是否相等。相等则不更新慢指针，只更新快指针；不相等时，先将慢指针后移一位，再将快指针指向的元素覆写入慢指针指向的单元，最后更新快指针（详见图解）。
边界：

当数组的长度小于等于 2 时，不需要操作，直接返回原数组即可。
初始化：

快指针用于遍历数组，但算法不可能操作序号小于 2 的元素，因此快指针初始值为 2；
初始状态下，慢指针应紧随快指针之后，因此初始值为 1；
结束条件：

快指针达到数组结尾。



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len; 
        int i = 1;
       for(int j=2;j<len;j++){
            if (nums[j] != nums[i-1])
                nums[++i]=nums[j];
        }
        return  i+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len; 
        int i = 1, j = 2;
        while (j < len)
        {
            if (nums[j] != nums[i-1])
                nums[++i]=nums[j];
            j++;
        }
        return  i+1;
    }
};
输入：[1,1,1,2,2,3]
输出：[1,1,2,2,3]
输入: [0,0,1,1,1,1,2,3,3]
输出: [0,0,1,1,2,3,3]

删除排序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0; 
        int i = 0, j = 0;
        while (j < len)
        {
            if (nums[i] != nums[j])
                nums[++i]=nums[j];
            j++;
        }
        return  i+1;
    }
};
输入：[1,1,2,2,3,3,4]
输出：[1,2,3,4]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0; 
        int i = 0, j = 0;
        while (j < len)
        {
            if (nums[i] != nums[j])
                swap(nums[++i],nums[j]);
            j++;
        }
        return  len;
    }
};

输入：[1,1,2,2,3,3,4]
输出：[1,2,3,4,1,3,2]