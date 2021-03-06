要用滑动窗口解这道题，我们要回答两个问题：

第一个问题，窗口何时扩大，何时缩小？
第二个问题，滑动窗口能找到全部的解吗？
对于第一个问题，回答非常简单：

当窗口的和小于 target 的时候，窗口的和需要增加，所以要扩大窗口，窗口的右边界向右移动
当窗口的和大于 target 的时候，窗口的和需要减少，所以要缩小窗口，窗口的左边界向右移动
当窗口的和恰好等于 target 的时候，我们需要记录此时的结果。设此时的窗口为 [i, j)[i,j)，那么我们已经找到了一个 ii 开头的序列，也是唯一一个 ii 开头的序列，接下来需要找 i+1i+1 开头的序列，所以窗口的左边界要向右移动

int left = 0, right = 0;
while (right < s.size()) {` // 增大窗口
		window.add(s[right]); right++;
		while (window needs shrink) { // 缩小窗口
		window.remove(s[left]);
		left++; 
	}
}

vector<vector<int>> findContinuousSequence(int target) {
    int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    vector<vector<int>> res;

    while (i <= target / 2) {
        if (sum < target) {
            // 右边界向右移动
            sum += j;
            j++;
        } else if (sum > target) {
            // 左边界向右移动
            sum -= i;
            i++;
        } else {
            // 记录结果
            vector<int> arr;
            for (int k = i; k < j; k++) {
                arr.push_back(k);
            }
            res.push_back(arr);
            // 左边界向右移动
            sum -= i;
            i++;
        }
    }

    return res;
}


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector< vector<int> > result;
        if(target < 3){
            return result;
        }
        int left = 1, right = 2;   //滑动窗口
        int middle = (target + 1) / 2;
        int sum = left + right;
        int n = -1;

        while(left < middle){
            if(sum < target){
                right++;
                sum += right;
            }
            else if(sum > target){
                sum -= left;
                left++;
            }
            else{
                n++;
                result.push_back(vector<int>());
                for(int k = left; k <= right; k++){
                    result[n].push_back(k);
                }
                sum -= left;
                left++;
            }
        }

        return result;
    }
};


