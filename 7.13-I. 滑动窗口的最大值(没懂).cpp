





思路描述：这个最简单的方法就是每次窗口滑动到一个位置就去计算一下这个窗口里的最大值，时间复杂度为 O(nk)


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return {};
        vector<int> ans;
        for(int i = 0; i <= nums.size() - k; i ++){
            int maxNum = nums[i];
            for(int j = i; j < i + k; j ++){
                maxNum = max(maxNum, nums[j]);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};

为了降低时间复杂度，我们观察一下窗口移动的过程类似于队列出队入队的过程，每次队尾出一个元素，
然后队头插入一个元素，求该队列中的最大值，这个和 包含min函数的栈 有点类似，我们可以维护一个递减队列，
队列用来保存可能是最大值的数字的index。当前窗口最大值的index在队首，当窗口滑动时，会进入一个新值，出去一个旧值，我们需要给出当前窗口的最大值。

需要先检查队首（上一窗口的最大值）的index是否还在当前窗口内，如果不在的话需要淘汰。
然后新进入的值要和队尾元素做比较，如果比队尾元素大，那么队尾元素出队（用到双端队列特性的地方），直到队列为空或者前面的值不比他小为止。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            //新元素入队时如果比队尾元素大的话就替代队尾元素
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            //检查队首的index是否在窗口内，不在的话需要出队
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            if (i >= k -1) ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};

