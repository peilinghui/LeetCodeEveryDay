389. 找不同
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：

输入：s = "", t = "y"
输出："y"
示例 3：

输入：s = "a", t = "aa"
输出："a"
示例 4：

输入：s = "ae", t = "aea"
输出："a"


标签：哈希表

本题最容易想到的就是使用哈希表进行运算，遍历第一个字符串标记出现的字符数量，再遍历第二个减去出现的数量，直到遇到为 0 或者原哈希表就不存在的情况

标签：异或运算

除了上述方法外，会有一个更 tricky 的解法，就是使用字符（注意不是字符串）异或运算，尽管并没有降低时间复杂度，但也是一种开阔思路的解题方式

使用异或运算可以解题主要因为异或运算有以下几个特点：

一个数和0做XOR运算等于本身：a⊕0 = a
一个数和其本身做XOR运算等于 0：a⊕a = 0
XOR 运算满足交换律和结合律：a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b
故而在以上的基础条件上，将所有数字按照顺序做抑或运算，最后剩下的结果即为唯一的数字

时间复杂度：O(m+n)O(m+n)，mm 为字符串 ss 的长度，nn 为字符串t的长度




/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    const map = new Map();
    for(let i = 0; i < s.length; i++) {
        const val = map.get(s[i]);
        map.set(s[i], val === undefined ? 1 : val + 1);
    }
    for(let i = 0; i < t.length; i++) {
        const val = map.get(t[i]);
        if(val === 0 || val === undefined) {
            return t[i];
        } else {
            map.set(t[i], val - 1);
        }
    }
};


异或运算的特性：

异或自己得0，任何数异或0得自己本身；
具有交换律、结合律，例如 1^2^3^4^2^3^1 = (1^1)^(2^2)^(3^3)^4 = 0^0^0^4 = 0^4 = 4;
总结：异或运算擅长找不同。
遍历两个字符串，时间复杂度O(m+n)
直接利用t[0]留存最后的答案，没有使用额外空间，空间复杂度O(1).

代码

class Solution {
public:
    char findTheDifference(string s, string t) {
        for (int i = 0; i < s.size(); ++i) t[0] ^= s[i];
        for (int i = 1; i < t.size(); ++i) t[0] ^= t[i];
        return t[0];
    }
};


class Solution {
public:
	char findTheDifference(string s, string t) 
	{
		int hash[26] = { 0 };
		for (int i = 0; i < s.size(); ++i)
			hash[s[i] - 'a']++;
		for (int i = 0; i < t.size(); ++i)
		{
			hash[t[i] - 'a']--;
			if (hash[t[i] - 'a'] == -1)
				return t[i];
        	}
		return -1;
	}
};



