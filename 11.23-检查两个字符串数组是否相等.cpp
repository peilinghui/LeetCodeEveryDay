1662. 检查两个字符串数组是否相等
给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。

数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。

 
示例 1：

输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
输出：true
解释：
word1 表示的字符串为 "ab" + "c" -> "abc"
word2 表示的字符串为 "a" + "bc" -> "abc"
两个字符串相同，返回 true
示例 2：

输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
输出：false
示例 3：

输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
输出：true



// 这个问题拼接字符串直接就可以过，不多说了。
// 拼接字符串的问题是使用了额外的空间，因为需要存储整个字符串。
// 这个问题可以直接在给定的数组上进行判断。
// 具体实现上，需要有 p1 和 p2 两个索引，指向数组 word1 和 word2。同时，还要有 i 和 j 两个索引，指向 word1[p1] 相应的字符和 word2[p2] 相应的字符。每一次比较的是 word1[p1][i] 和 word2[p2][j]。
// 关键是，在比较完一个字符以后，如何看下一个字符？其实也很简单。i ++，但如果 i 走到了 word1[p1].size() 的话，p1 ++，i 归零。j 同理。
// 整个循环的条件是 while(p1 < word1.size() && p2 < word2.size())，在循环结束后，还要判断一下，是不是 p1 和 p2 都走到了 word1 和 word2 的最后。



// 整个代码并不复杂。我的参考代码（C++）：


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        int p1 = 0, p2 = 0, i = 0, j = 0;
        while(p1 < word1.size() && p2 < word2.size()){

            if(word1[p1][i] != word2[p2][j]) return false;

            i ++;
            if(i == word1[p1].size()) p1 ++, i = 0;

            j ++;
            if(j == word2[p2].size()) p2 ++, j = 0;
        }
        return p1 == word1.size() && p2 == word2.size();
    }
};
这样做，空间是 O(1) 的。





class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto it:word1)a+=it;
        for(auto it:word2)b+=it;
        return a==b;
    }
};


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        vector<char>a;
        vector<char>b;
        for(int i = 0 ; i < w1.size();i++) {
            for(int j = 0 ; j < w1[i].size();j++) {
                a.push_back(w1[i][j]);
            }
        }
        for(int i = 0 ; i < w2.size();i++) {
            for(int j = 0 ; j < w2[i].size();j++) {
                b.push_back(w2[i][j]);
            }
        }
        if(a == b) {
            return true;
        }
        else return false;
    }
};
