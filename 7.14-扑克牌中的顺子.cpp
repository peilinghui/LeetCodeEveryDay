不能有重复元素

最大的牌不能比非0最小牌大4

代码

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0 ;
        while(i<nums.size()&&nums[i]==0)i++;//i指向非零元素
        if(i==nums.size()) return true;//全为0时 特判
        for(int j =i;j<4;j++){
            if(nums[j] == nums[j+1]) return false;//判断其中是否有大小相同的牌
        }
        return nums[4]-nums[i]<=4;//最大的牌和非0最小牌不能超过4
    }
};


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //统计0的个数
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] == 0) cnt ++;
            else if(nums[i] == nums[i+1]) return false;
            //产生的跳跃
            else if(nums[i] + 1 != nums[i+1]){
                cnt -= (nums[i+1] - nums[i] - 1);
            }
        }
        return cnt >= 0;
    }
};


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int upper = -1;
        int lower = 100;

        for (auto num: nums) {
            cnt[num]++;
            if (num != 0) {
                if (cnt[num] > 1) return false;
                upper = max(upper, num);
                lower = min(lower, num);
            }
        }

        if (cnt[0] >= 4) return true;
        int delta = upper - lower;
        if (delta >= 5) return false;

        return true;        
    }
};

