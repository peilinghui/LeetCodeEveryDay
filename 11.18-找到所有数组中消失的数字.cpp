不能使用额外的数组空间，我们可以把元素放到相应的位置，当元素都放到对应的位置时，结束循环；
时间复杂度为 O（2n），不需要使用任何额外空间

代码

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        //使用原地hash的思想，将元素首先放到对应的位置
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                while(nums[i]!=nums[nums[i]-1]){
                    swap(nums[i],nums[nums[i]-1;]);
                }
            }
        }
        vector<int>res;
        for(int  i=0;i<n;i++){
            if(nums[i]!=i+1)res.push_back(i+1);
        }
        return res;
    }
};




