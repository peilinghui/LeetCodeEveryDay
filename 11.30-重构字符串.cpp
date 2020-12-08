767. 重构字符串
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""








要保证相邻字符不同，我们需要贪心地对字符串进行重构，也就是在下一次重构的时候，把剩余字符串里最多的字符放到我们的重构字符串里。然后把本次重构去掉的字符再添加回去（放回的个数-1，因为我们已经用过一次了）。

如何理解剩余字符串？
假设已知当前字符串里字母a出现的次数最多，那么这次我们肯定是把字母a添加到答案中，接下来我们把字符串里的所有字母a都去掉，这就是剩余字符串。在下一次重构的时候，假设这时字符串里字母b出现的次数最多，那么我们就把字母b添加到答案中，然后去掉字符串里所有的字母b，再把上一次去掉的a再放回去（放回的个数-1）。以此类推……
如果暴力地对字符串进行删除和添加的操作，那么我们的时间复杂度会达到O(n^2)O(n 
2
 )。我们可以借助最大堆这个数据结构把时间复杂度降低到O(nlog26)O(nlog26)，也就是O(n)O(n)。最大堆保证了堆顶永远是出现次数最多的那个字母。

什么情况下无法完成重构？
出现次数最多的那个字母大于字符串的长度的一半，向上取整。即长度为10的字符串，字母出现次数大于5；长度为11的字符串，字母出现的次数大于6。



核心算法如下：


初始化一个堆 pq，堆的每个元素包含了字母(char)和它的个数(count)
初始化一个变量prev，记录上次去掉的字母和它的个数

当堆不为空：
    cur = 堆顶元素
    弹出堆顶元素
    res = res + cur.char
    if prev.count > 0:
        将prev添加到堆中
    更新prev：prev = (cur.count-1,cur.char)


class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        vector<int> counter(26,0);
        priority_queue<pair<int,char>> pq;

        // 统计字母出现的次数
        for(auto& c: S)
            counter[c-'a']++;
        
        // 遍历哈希表
        for(int i = 0;i < 26;i++){
            // 边界条件
            if(counter[i] > (S.size()+1)/2)
                return "";

            // 把字母添加到优先队列中
            if(counter[i] > 0) 
                pq.push({counter[i],i+'a'});
        }
        
        pair<int,char> prev(0,' ');
        
        // 开始重构字符串
        while(!pq.empty()){
            pair<int,char> cur = pq.top();
            pq.pop();
            res += cur.second;
            cur.first--;
            if(prev.first > 0)
                pq.push(prev);
            prev = cur;
        }
        return res;
    }
};

