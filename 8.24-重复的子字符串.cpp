459. 重复的子字符串:【KMP经典问题】

这是一道标准的KMP的题目。

使用KMP算法，next 数组记录的就是最长公共前后缀， 最后如果 next[len - 1] != -1，说明此时有最长公共前后缀（就是字符串里的前缀子串和后缀子串相同的最长长度），同时如果len % (len - (next[len - 1] + 1)) == 0 ，则说明 (数组长度-最长公共前后缀的长度) 正好可以被 数组的长度整除，说明有重复的子字符串。

强烈建议大家把next数组打印出来，看看next数组里的规律，有助于理解KMP算法



此时next[len - 1] = 7，next[len - 1] + 1 = 8，8就是此时 字符串asdfasdfasdf的最长公共前后缀的长度。

(len - (next[len - 1] + 1)) 也就是： 12(字符串的长度) - 8(最长公共前后缀的长度) = 4， 4正好可以被 12(字符串的长度) 整除，所以说明有重复的子字符串。

代码如下：

C++代码

class Solution {
public:
    void preKmp(int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1;i < s.size(); i++){
            while(j >= 0 && s[i] !=s [j+1])
                j = next[j];
            if(s[i] == s[j+1])
                j++;
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        preKmp(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;

    }
};


class Solution {
public:
    vector<int> buildNext(string pat)
    {
        int m=pat.size(),j=0;
        vector<int> next(m+1,-1);
        int t=-1;
        while(j<=m-1)//注意，不同于经典的buildNext实现(小于号)。这里是小于等于
        {
            if(0>t || pat[j]==pat[t])
            {
                next[++j]=++t;
            }
            else t=next[t];
        }
        return next;
    }

    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int> next=buildNext(s);
        int x=next[n];//取出最后一位
        return x && n%(n-x)==0;
    }
};
