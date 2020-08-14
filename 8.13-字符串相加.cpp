
415. 字符串相加


给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。



这和我们大一用C语言学程序设计时，做过比较多次的大整数相加是同一道题，但是这回看了大家的题解觉得受教了受教了！原来可以不用写的很啰嗦。
方法：
定义两个指针分别指向两个串的当前需要被执行加法的数字位，对于string，看做数组下标，需要从后向前递减指针数值
每一轮循环的时候，如果这个数字还没有被加完（也就是一个数字比另一个长的情况）那么就让x是当前对应的数字，如果被加完了，那么就直接为0，x和y的和就是curAdd
让变量add维护每一轮的进位（curAdd + add)/10
并把余数变为字符，续在ans字符串后面
当i和j都为0，并且进位add=0的时候，说明已经完成整个加法
将ans整个反转过来就得到所求答案


c++ 双指针求和

class Solution {
public:
    string addStrings(string num1, string num2) {
        int sum = 0, i = num1.size() - 1, j = num2.size() - 1;
        string ans = "";
        while (i >= 0 || j >= 0 || sum) {
            if(i >= 0) sum += num1[i--] - '0';
            if(j >= 0) sum += num2[j--] - '0';
            ans = (char)('0' + sum % 10) + ans;
            sum /= 10;
        }
        return ans;
    }
};

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int ln1 = num1.length() - 1;
        int ln2 = num2.length() - 1;
        int carry = 0;
        //定义一个空字符串，一边后面插入数字字符
        string c = "";
        while(carry == 1 || ln1 >= 0 || ln2 >= 0)
        {
            //z一定要把num1和num2分开考虑，防止出现因两数的位数不同而出现错误
            int x = ln1 < 0 ? 0 : num1[ln1--] - '0';
            int y = ln2 < 0 ? 0 : num2[ln2--] - '0'; 
            //记得此处转换为char型，以及后面加'0'
            c.insert(0,1,char(x+y+carry) % 10 +'0');
            //carry表示进位
            carry = (x+y+carry)/10;
        }
        return c;
    }
};




class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        //定义两个指针，从后向前
        int i = num1.size()-1;
        int j = num2.size()-1;

        int add = 0;//进位
        int x,y;//用来保存当前用来做加法的数字
        int curAdd=0;//保存不考虑进位的和
        string ans = "";//初始化为空字符串

        while(i>=0 || j>=0 || add!=0)
        {
            x = i>=0? (num1[i] - '0') : 0;
            y = j>=0? (num2[j] - '0') : 0;
            curAdd = x+y;

            ans.push_back('0' + (curAdd+add)%10 );//mod10之后的余数
            add = (curAdd+add)/10;//商做进位
            //更新指针
            i--;
            j--;
        }
        //反转ans
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

