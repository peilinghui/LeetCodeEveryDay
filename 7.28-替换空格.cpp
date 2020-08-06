两点要注意：
1）替换后字符串长度变长
2）从后向前是为了防止覆盖原字符
3）注意下字符串的末尾“\0”对程序的影响

代码

class Solution {
public:
    string replaceSpace(string s) {
        int len1=s.length()-1;
        for(int i=0;i<=len1;i++){
            if(s[i]==' ')
            {
                s+="00";
            }
        }
        int len2=s.length()-1;
        if(len2<=len1){
            return s;
        }
        for(int i=len1;i>=0;i--){
            char c=s[i];
            if(c==' '){
                s[len2--]='0';
                s[len2--]='2';
                s[len2--]='%';
            }
            else{
                s[len2--]=c;
            }
        }
        return s;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto c : s){
            if(c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
};


string replaceSpace(string s)
    {
        string res;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                res += s[i];
            }
            if(s[i] == ' ')
            {
                res += "%20";
            }
        }
        return res;
    }