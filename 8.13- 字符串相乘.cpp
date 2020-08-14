

1. 把两个数用数组 a, b 来存储，并且反转（从个位开始乘）
2. 对于 a 的第 i 位 和 b 的第 j 位相乘的结果存储在 c[i + j] 上，即 c[i + j] += a[i] * b[j];
这里用加号是因为有多种情况都会映射到 i + j 位上。
3. 最后，从 c 的低位向高位整理，c[i + 1] = c[i] / 10, c[i] %= 10;

                            1   2   3
                        乘  4   5   6
                    ————————————————————
                            6   12  18
                        5   10  15
                    4   8   12
                    ————————————————————
                    4   13  28  27  18
                    整理： c[i + 1] += c[i] / 10, c[i] %= 10, 从低位开始。
                    step 0: 4   13  28  27  18
                    step 1: 4   13  28  28  8
                    step 2: 4   13  30  8   8
                    step 3: 4   16  0   8   8
                    step 4: 5   6   0   8   8



class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        vector<int> a, b, c;
        c.resize(num1.size() + num2.size() - 1);
        for (int i = num1.size() - 1; i >= 0; i--) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i--) b.push_back(num2[i] - '0');
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        int k = 0;
        for (int i = 0; i < c.size(); i++) {
            k += c[i];
            char c = k % 10 + '0';
            ans = c + ans;
            k /= 10;
        }
        while (k) {
            char c = k % 10 + '0';
            ans = c + ans;
            k /= 10;
        }
        while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
        return ans;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        // handle edge-case where the product is 0
        if (num1 == "0" || num2 == "0") return "0";
        
        // num1.size() + num2.size() == max no. of digits
        vector<int> num(num1.size() + num2.size(), 0);
        
        // build the number by multiplying one digit at the time
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        
        // skip leading 0's
        int i = 0;
        while (i < num.size() && num[i] == 0) ++i;
        
        // transofrm the vector to a string
        string res = "";
        while (i < num.size()) res.push_back(num[i++] + '0');
        
        return res;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n= num2.size();
        //结果最多为m+n位
        vector<int> res(m+n,0);
        //从个位数开始逐位相乘
        for(int i = m-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                //乘积在res对应的索引位置
                int p1 = i+j,p2=i+j+1;

                //叠加到res上
                int sum = mul +res[p2];
                res[p2] = sum%10;
                res[p1]+=sum/10;
            }
            //结果前缀可能存的0（未使用的位）
            int i=0;
            while(i<res.size() && res[i]==0) i++;

            string str;
            for(;i<res.size();i++)  
            str.push_back('0'+res[i]);

            return str.size()==0 ?"0":str;
    }
};
