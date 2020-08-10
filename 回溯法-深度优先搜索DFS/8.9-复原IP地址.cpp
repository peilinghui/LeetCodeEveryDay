回溯法的关键是找出能记录当前状态，且可以判断是否得到结果的回溯条件。

对于这道题来说首先把问题转换为在字符串中加.号,保证.号间字符串表示的数小于等于255。回溯条件就是当前加了几个.号和上一个.号的位置。

class Solution {
private:
    vector<string> res;
    string path;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
        return {};
        dfs(0, s, 0, path);
        return res;             
    }

    void dfs(int cur_count, string s, int start, string path){
        if(cur_count == 4){   //当达到4个分组，且s已经遍历完时，将结果输出到res中
            if(start == s.size())
            res.push_back(path);
            return;
        }
        
        for(int i = 1; i < 4 && start + i <= s.size(); ++i){  //遍历+回溯，每次尝试1、2、3个元素为当前节
            string tmp = s.substr(start, i);                  //必须加上start + i <= s.size()，因为遍历到s末尾后会越界
            if(check(tmp)){
                if(cur_count < 3)   //注意'.'的输出次数
                tmp += '.';
                dfs(cur_count + 1, s, start + i, path + tmp); //遍历、回溯
                if(s[start] == '0') //此处排除0x和0xx的情况
                return;
            }
            else{
                return;   //当前所选节是无效的，就得返回
            }
        }

    }

    bool check(string str){  //判断是否符合0-255
        int tmp = stoi(str);
        if(tmp >= 0 && tmp <= 255)
        return true;
        return false;
    }
};


class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        string cur = s;
        helper(n,0,-1,cur,s);
        return res;
    }
    void helper(int n,int pointnum,int lastpoint,string& cur,string& s) {
        //pointnum记录目前加了几个点了，lastpoint记录上一个点加的位置
        if (pointnum == 3) {
        //如果已经加了三个点了，并且最后一个点的右边表示的数小于255，则是正确IP地址
            if (valid(lastpoint + 1,n-1,s)){
                res.push_back(cur);
            }
            return;
        }
        //从上一个.号的下一个位置开始查找
        for (int i = lastpoint + 1;i < n - 1;i++) {
            //如果字符串s从上一个.号到i位置表示的数小于等于255，则符合条件
            if (valid(lastpoint + 1,i,s)){
                //正常回溯法，注意这里要+pointnum，因为已经加入的.号也会占位
                cur.insert(cur.begin() + i + pointnum + 1,'.');
                helper(n,pointnum + 1,i,cur,s);
                cur.erase(pointnum + i + 1,1);
            }
        }
        return;
    }
    bool valid(int left,int right,string& s) {
        int sum = 0;
        for (int i = left ;i <= right; i++) {
            //处理0开头问题
            if (left != right and s[left] == '0' ) return false;
            //计算字符串s中left到right位表示的数的大小
            sum = sum *10 + (s[i] - '0');
            if (sum > 255) return false;
        }
        return true;
    }
};



class Solution {
public:
    int l;
    vector<string> ans;
    void dfs(int id, int step, int mmin, string s) {

        if (mmin <= 0) mmin = 1;

        int tmp;
        for (int i = mmin; i <= 3; ++i) {
            tmp = 0;
            for (int j = 0; j < i; ++j) {
                tmp = tmp*10 + (s[j+id]-'0');
            }
            if (s[id] == '0' && i > 1) { return;}
            if (0 <= tmp && tmp <= 255) {
                if (l == i) {
                    if (step == 4) { ans.push_back(s);}
                    return;
                }
                l -= i;
                dfs(id+i+1, step+1, l-(4-1-step)*3, s.substr(0, id+i) + "." + s.substr(id+i, l));
                l += i;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        l = s.length();
        dfs(0, 1, l-(4-1)*3, s);
        return ans;
    }
};


class Solution {
public:
	vector<string> res;

	bool isValid(const string& tmp)
	{
		if (tmp[0] == '0' && tmp.size() > 1)  return false;

		int num = stoi(tmp);
		if (0 <= num && num <= 255) return true;
		else return false;
	}

	void dfs(string& s, int depth, vector<string>& tmp)
	{
       	// 树深剪枝
		if (depth == 4 && s.size() != 0)	return;

    	// 合并结果串(IP段)
		if (depth == 4 && s.size() == 0)
		{
			string a;
			for (int i = 0; i < 4; ++i)
			{
				a += i != 3 ? tmp[i] + "." : tmp[i];
			}
			res.push_back(a);
			return;
		}

		// 长度剪枝
		if (s.size() < 4 - depth || s.size() > 12 - 3 * depth)   return;

		for (int i = 1; i <= 3; ++i)
		{
			if (i > s.size())	continue;

			// 当前子串(IP段)剪枝
			string subStr = s.substr(0, i);
			if (isValid(subStr))
			{
				tmp.push_back(subStr);
				string leftStr = s.substr(i);

				dfs(leftStr, depth + 1, tmp);
				tmp.pop_back();
			}
		}
	}
public:
	vector<string> restoreIpAddresses(string s)
	{
		if (s.size() < 4 || s.size() > 12)  return {};

		vector<string> tmp;
		dfs(s, 0, tmp);

		return res;
	}
};
