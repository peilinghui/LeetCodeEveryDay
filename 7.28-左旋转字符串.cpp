解法一 遍历

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans = "";
        for (int i = n; i < s.size(); ++i) ans += s[i];
        for (int i = 0; i < n; ++i) ans += s[i];
        return ans;
    }
};
解法二 切片一

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return (s + s).substr(n, s.size());
    }
};
解法三 切片二

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string a1(s, 0, n);
        string a2(s, n);
        return a2 + a1;
    }
};
解法四 三次翻转

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
