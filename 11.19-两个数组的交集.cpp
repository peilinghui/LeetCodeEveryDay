349. 两个数组的交集
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]


//排序+双指针
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; //记录最终的答案
        sort(nums1.begin(),nums1.end());//对nums1进行排序
        sort(nums2.begin(),nums2.end());//对nums2进行排序
        int place1=0;//记录nums1数值的下标
        int place2=0;//记录nums2数值的下标

        //对nums1和nums2进行数值比较
        while(place1<nums1.size() && place2<nums2.size()){
            //当两个数相等时
            if(nums1[place1]==nums2[place2]){
                //如果当前ans数组中没有放入数字，则直接放，然后更新place1和place2
                if(ans.size()==0){
                    //将相同的数字放入数组ans
                    ans.push_back(nums1[place1]);
                }
                //如果当前的ans中有数字，为了避免重复，则当前数和前一个数进行比较
                else{
                    int len=ans.size()-1;
                    //如果当前数和前一个数不相等，则存入数组ans中，否则不存
                    if(nums1[place1]!=ans[len]){
                        ans.push_back(nums1[place1]);
                    }
                }

                //更新place1和place2，同时向后移一位
                place1++;
                place2++;
            }//如果两数不相等，则移动小的那个下标
            else if(nums1[place1]<nums2[place2]){ 
                place1++;
            }else{
                place2++;
            }
        }
        //返回最终结果数组
        return ans;

    }
};

解题思路


解法2：双指针

解法3：二分

代码

//解法1： 哈希表
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> h,h1;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            h.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(h.count(nums2[i])&&h1.count(nums2[i])==0)
            {
                h1.insert(nums2[i]);
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};


class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for (const auto& num : nums1) {
            st.insert(num);
        }

        vector<int> res;
        for (const auto& num : nums2) {
            if (st.count(num)) {
                res.push_back(num);
                st.erase(num);
            }
        }

        return res;
    }
};
// Two pointers


class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        int N = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0; 
        int j = 0;
        vector<int> res;
        while (i < M || j < N) {
            auto val1 = i < M ? nums1[i] : INT_MAX;
            auto val2 = j < N ? nums2[j] : INT_MAX;
            if (val1 == val2) {
                res.push_back(nums1[i]);
                int k = i;
                while (k < M && nums1[k] == nums1[i]) {
                    k++;
                }
                i = k;
                k = j;
                while (k < N && nums2[k] == nums2[j]) {
                    k++;
                }
                j = k;
            } else if (val1 < val2) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};
// Binary search
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        int N = nums2.size();
        unordered_set<int> st;
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        for (const auto& num : nums1) {
            int index = binarySearch(nums2, num);
            if (index != -1 && !st.count(num)) {
                res.push_back(num);
                st.insert(num);
            }
        }

        return res;
    }

private:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (left == nums.size() || nums[left] != target) {
            return -1;
        }

        return left;
    }
};


