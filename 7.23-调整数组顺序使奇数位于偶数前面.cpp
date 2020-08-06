首尾双指针
定义头指针 leftleft ，尾指针 rightright .
leftleft 一直往右移，直到它指向的值为偶数
rightright 一直往左移， 直到它指向的值为奇数
交换 nums[left]nums[left] 和 nums[right]nums[right] .
重复上述操作，直到 left == rightleft==right .


代码

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left ++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right --;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
快慢双指针
定义快慢双指针 fastfast 和 lowlow ，fastfast 在前， lowlow 在后 .
fastfast 的作用是向前搜索奇数位置，lowlow 的作用是指向下一个奇数应当存放的位置
fastfast 向前移动，当它搜索到奇数时，将它和 nums[low]nums[low] 交换，此时 lowlow 向前移动一个位置 .
重复上述操作，直到 fastfast 指向数组末尾 .


代码

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {
                swap(nums[low], nums[fast]);
                low ++;
            }
            fast ++;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int left = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums.at(i) % 2 != 0)
            {
                swap(nums.at(i), nums.at(++left));
            }
        }
        
        return nums;
    }
};



a按位与操作，1 & 1 = 1， 0 & 1 = 0，一个数二进制表示最后一位是1那它就是奇数，按位&1结果为1，一个数是偶数，二进制表示最后一位为0，按位&1结果为0。相当于% 2 == 1