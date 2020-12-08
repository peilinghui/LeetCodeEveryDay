4. 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if(tot % 2) {//总数为奇数时的中位数
            return find(nums1, 0, nums2, 0, tot/2+1);
        }
        else {
            int l = find(nums1, 0, nums2, 0, tot/2), r = find(nums1, 0, nums2, 0, tot/2 + 1);
            return (l + r)/2.0;
        }
    }

    //转为寻找第k小数问题,从nums1中的i和nums2的j开始 找第k大的数
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        //保证第二个大于等于第一个
        if(nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);
        //第一个数组为空时 
        if(nums1.size() == i) return nums2[j+k-1];
        if(k==1) return min(nums1[i],nums2[j]);//递归边界 即为两个最小值
        int si = min(int(nums1.size()),i + k/2), sj = j + k - k/2;//每个数组从起点开始的第k/2大数的后一个数的下标
        if(nums1[si-1] > nums2[sj-1]){//若前者的该数大于后者的该数 则后者的前部分就没用了
            return find(nums1, i, nums2, sj, k - (sj-j));//sj-j即为删去的数的个数
        }
        else return find(nums1, si, nums2, j, k - (si - i));//同理 此时 前者的前部分就没用了
    }
};