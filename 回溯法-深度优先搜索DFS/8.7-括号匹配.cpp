在什么情况下添加左括号呢？很明显，最多能添加 n 个左括号，在递归调用的时候，在能传递到最底层的共用字符串中先添加 ”(“ ，然后 left-1，递归调用就可以。

那什么时候添加右括号呢？当左括号个数大于右括号的个数时添加右括号。

总之，向下搜索要满足两个条件：

插入数量不超过n
可以插入 ） 的前提是 ( 的数量大于 ）

回溯法的代码套路是使用两个变量： res 和 path，res 表示最终的结果，path 保存已经走过的路径。如果搜到一个状态满足题目要求，就把 path 放到 res 中。

代码后面的判断条件都是 if，而不是 elif，因为是满足两个条件的任意一个就可以继续向下搜索，而不是同时只能满足其中的一个。


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int lc = 0, rc = 0;
        dfs(res, "", n, lc, rc);
        return res;
    }
    void dfs(vector<string>& res, string path, int n, int lc, int rc) {
        if (rc > lc || lc > n || rc > n) return;
        if (lc == rc && lc == n) {
            res.push_back(path);
            return;
        }
        dfs(res, path + '(', n, lc + 1, rc);
        dfs(res, path + ')', n, lc, rc + 1);
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }

    void dfs(vector<string> & res, string  str,int left,int right)
    {
        if(left == 0 && right == 0)             res.push_back(str); 
        if(left > 0)          dfs(res, str + "(", left - 1, right);
        if(right > left)      dfs(res, str + ")", left, right - 1);
    }
};


此题我们要保证生成的括号字符串合法。
我们用l，r分别记录可以插入 '(' 和 ')' 的数量。
例如n = 3，那么一开始r = 0，l = 3。
当我们在递归函数中，选择插入 '(' 时，r要 + 1,l要 - 1，。
因为你插入你一个'('势必要在接下来插入一个')'。
当我们在递归函数中，选择插入 ')' 时，r只需- 1即可


class Solution {
public:
    void getAns(string str, int l, int r, vector<string>& ans){
        if(l == 0 && r == 0)
            ans.push_back(str);
        if(l > 0)
            getAns(str + "(", l - 1, r + 1, ans);
        if(r > 0) 
           getAns(str + ")", l, r - 1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getAns("", n, 0, ans);
        return ans;
    }
};


class Solution {
public:
    void work(const string &str, int lc, int rc, int n, vector<string> &res) {
        if(str.size() == n) {
            res.push_back(str);
            return;
        }
        if(rc < lc) {
            work(str+")", lc, rc+1, n, res);
        }
        if(lc+1-rc <= n-str.size()-1) {
            work(str+"(", lc+1, rc, n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        work("", 0, 0, n*2, res);
        return res;
    }
};
