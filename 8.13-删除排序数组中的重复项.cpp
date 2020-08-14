//双指针--i是慢指针，而j是快指针。nums[i]=nums[j]，我们就增加j以跳过重复项。
//当我们遇到 nums[j] != nums[i]把nums[j]的值复制到nums[i + 1],
//递增i，接着我们将再次重复相同的过程，直到j到达数组的末尾为止。
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0) return 0; 
        int i = 0, j = 0;
        while (j < len)
        {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
            j++;
        }
        return i + 1;
    }
    int removeDuplicates(vector<int>& nums){
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
};

 


