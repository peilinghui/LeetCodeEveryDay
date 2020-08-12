
先统计连续的0和1分别有多少个，如：111100011000，得到4323；在4323中的任意相邻两个数字，取小的一个加起来，就是3+2+2 = 7.
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ptr = 0, n = s.size();
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for (int i = 1; i < counts.size(); ++i) {
            ans += min(counts[i], counts[i - 1]);
        }
        return ans;
    }
};

这个实现的时间复杂度和空间复杂度都是 O(n)O(n)。



class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int res{0};
        for(int i=0; i<n-1; i++){
            if(s[i]!=s[i+1]){
                res++;
                for(int j=1; j<i+1; j++){
                    if(s[i-j]==s[i-j+1] && s[i+j+1]==s[i+j]){
                        res++;
                    }else{
                        break;
                    }
                }
            }
        }
        return res;
        
    }
};

