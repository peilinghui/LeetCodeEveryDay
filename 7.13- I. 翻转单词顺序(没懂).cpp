方法二：
1.反转每个单词：eht yks si eulb
2.反转整个字符：blue is sky the

代码
cpp

//先翻转单个单词，后翻转整个字符串
//最后，会出现首、尾元素是空格的情况，erase去除
//中间也会出现多个空格连接的情况，仅保留一个

输入: "the sky is blue"
输出: "blue is sky the"


class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); ++ i){
            while (i < s.size() && s[i] == ' ') ++i;  //找到第一个非空格字符
            if (i == s.size()) break;
            int j = i;
            while (j < s.size() && s[j] != ' ') ++j;    //遍历1个非空单词
            reverse(s.begin() + i, s.begin() + j);      //反转1个单词
            if (k) s[k++] = ' ';
            while (i < j) s[k++] = s[i++];      //反转后的1个单词赋给s[k]
        }
        s.erase(s.begin() + k, s.end());   //删除 k后面空格
        reverse(s.begin(), s.end());
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int len = 0;
        string ans = "";
        for(int m = s.size()-1; m >=0; m--)
        {
            if(s[m]==' '&&len!=0)
            {
                ans += s.substr(m+1,len)+ " ";len = 0; continue;
            }
            if(s[m]!= ' ')len++;
        }
        if(len !=0) ans += s.substr(0,len) + " ";
        if(ans.size()>0)ans.erase(ans.size()-1,1);
        return ans;

    }
};



