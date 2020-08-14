给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。


和普通的判断括号有效是一样的，只不过现在要判断两个括号是否匹配，所以新加一个函数就好了
基本步骤就是，把括号依次压入栈，如果发现要压入的字符和栈顶的字符，也就是刚才压进去的字符匹配
那么就把这个字符出栈就好了，因为这两个已经组成括号了，不影响后面的判断
最后如果所有的括号都匹配好了，那么栈一定是空的

代码

class Solution {
public:
    bool isPair(char a, char b){
        if(a == '(' && b == ')') return true;
        if(a == '[' && b == ']') return true;
        if(a == '{' && b == '}') return true;
        return false;
    }
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> stk;
        stk.push(s[0]);
        for(int i = 1; i < s.size(); i ++){
            if(!stk.empty() && isPair(stk.top(), s[i])) stk.pop();
            else stk.push(s[i]);
        }
        return stk.empty();
    }
};



class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

