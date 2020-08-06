class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
                return {l + 1, r + 1};
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int t = numbers[l] + numbers[r];
            if (t == target) {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            } else if (t < target) l ++;
            else r --;
        }
        return ans;
    }
};


var twoSum = function(numbers, target) {
    let low = 0;
    let high = numbers.length -1;
    while(low < high) {
        let sum = numbers[low] + numbers[high];
        if(sum === target) {
            return [++low,++high]
        } else if(sum < target) { // 如果比目标值小，我们将较小元素指针增加一
            low ++
        } else { // 如果比目标值大，我们将较大指针减小一
            high --;
        }
    }
    return null
};