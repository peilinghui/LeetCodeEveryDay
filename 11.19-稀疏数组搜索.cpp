面试题 10.05. 稀疏数组搜索
稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

示例1:

 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 输出：-1
 说明: 不存在返回-1。
示例2:

 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 输出：4




三种方法解决稀疏数组的搜索
LeeZH
发布于 2020-09-16
27
三种方法中，二分法看似比暴力法好，但是空字符串数量很多时，时间大部分被空格检索花费
综合时间性能并没有比暴力法有明显优势
三种方法中最快的是用find函数
方法一 暴力法


class Solution {
public:
    int findString(vector<string>& words, string s) {
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==s)
                return i;
        }
        return -1;
    }
};
方法二 二分法


class Solution {
public:
    int findString(vector<string>& words, string s) {
        int l=0;
        int r=words.size()-1;
        while(l<=r)
        {
            while(words[l]=="") l++;
            while(words[r]=="") r--;
            int mid=(l+r)/2;
            while(words[mid]=="") mid++;
            if(words[mid]==s)
                return mid;
            else if(words[mid]<s)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};
方法三 find函数


class Solution {
public:
    int findString(vector<string>& words, string s) {
        auto it = find(words.begin(), words.end(), s);
        if (it != words.end()) return it - words.begin();
        else return -1;
    }
};


通过findIdex判断判断是否相等返回相应下标

代码

/**
 * @param {string[]} words
 * @param {string} s
 * @return {number}
 */
var findString = function(words, s) {
    return words.findIndex(function(value, index, arr) {
        return value === s
    })
};

var findString = function(words, s) {
   let map = new Map()
   for(let i = 0; i< words.length; i++){
     map.set(words[i], i)
   }
    return map.has(s) ? map.get(s) : -1 
};

