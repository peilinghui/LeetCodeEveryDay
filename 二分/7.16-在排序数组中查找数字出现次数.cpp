


利用两次二分法分别找到重复相同数字的左边界x和右边界y


class Solution {
public:
    int search(vector<int>& nums, int target) {
            if(nums.empty()) return 0;
        
            int x,y;
            int left = 0, right = nums.size()-1,mid;
            while(left < right){
                mid = (left + right)/2;
                if(nums[mid] >=target) right = mid;
                else left = mid + 1;
            }

            if(nums[left]!=target) return 0;
            x=left,right = nums.size();
            while(left<right){
                mid=(left + right)/2;
                if(nums[mid] <=target) left = mid+1;
                else right=mid;
            }
            y = left;
        return y-x;
    }
};

先利用二分查找找到目标的下标，
若找不到，则直接返回0；
找到了，再以该下标为中心，向两边延伸。

代码

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin=0;
        int end=nums.size()-1;
        int it=-1;
        while(end>=begin)
        {
             int mid=begin+(end-begin)/2;        
             if(nums[mid]>target)end=mid-1;
             else if(nums[mid]==target)
             {
                 it=mid;
                 break;
             }
             else begin=mid+1;
        }
        if(it==-1)return 0;
        int left=it;
        int right=it;
        while(left>=0&&nums[left]==target)left--;
        while(right<nums.size()&&nums[right]==target)right++;
        return right-left-1;
    }
};

