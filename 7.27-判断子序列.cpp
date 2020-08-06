




class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0, p2 = 0;
        int ss = s.size();
        int st = t.size();
        while(p1 != ss && p2 != st){
            if(s[p1] == t[p2]){
                p1++;
            }
            p2++;
        }
        return p1 == ss;
    }
};