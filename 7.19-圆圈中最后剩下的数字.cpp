class Solution {
    int f(int n, int m) {
        if (n == 1)
            return 0;
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};


class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;// 最终活下来那个人的初始位置
        for (int i = 2; i != n + 1; ++i)
            f = (m + f) % i;// 每次循环右移
        return f;
    }
};
