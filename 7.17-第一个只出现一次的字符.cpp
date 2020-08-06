由于给定字符串中只包含小写字母，而小写字母只有26个，因此可以定义一个大小为26的整数数组来保存字符串中出现的各个小写字母的个数，最后再遍历一遍给定字符串找到第一个出现一次的字符并返回。
时间复杂度：O(N);
空间复杂度：O(1);

代码

class Solution {
public:
    char firstUniqChar(string s) {
        int a[26] = {0};
        if(s == "") return ' ';
        for(int i = 0; i < s.size(); i++)
        {
            int b = s[i] - 'a';
            a[b] += 1;
        }
        for(int i = 0; i < s.size(); i++)
        {
            int b = s[i] - 'a';
            if(a[b] == 1) return s[i];
        }
        return ' ';
    }
};

class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "")
            return ' ';
        //map中是对应字符出现的次数
        unordered_map<char,int> cmap;
        for(auto i = 0;i < s.size();i++)
        {
            cmap[s[i]]++;
        }
        //按字符串的顺序在map中查找到第一个出现一次的字符
        for(auto i = 0;i < s.size();i++)
        {
            if(cmap[s[i]] == 1)
                return s[i];
        }
        //没有找到
        return ' ';
    }
};
