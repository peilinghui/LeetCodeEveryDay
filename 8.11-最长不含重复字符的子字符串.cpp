class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>window;//哈希表
        int left=0,right=0,res=0;//记录长度
        while(right<s.size()){//右移
            char c= s[right];
            window[c]++;
            right++;
            while(window[c]>1){//左移
                char d=s[left];
                window[d]--;
                left++;
            }
            res = max(res,right-left);
        }
        return res;
    }
};




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int length=0;
        while(i<s.size()&&j<s.size()){
            //右指针右移
            if(j<s.size()&&mp[s[j]]<1){
                mp[s[j]]++;  
                j++;
            }
            
            //左指针左移
            else{
                mp[s[i]]--;
                i++;
            }
            length=max(length,j-i);
        }
        return length;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ret = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r++]] = r;
            ret = max(r - l, ret);
        }
        return ret;
    }
};

