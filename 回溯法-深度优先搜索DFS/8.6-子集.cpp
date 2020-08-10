
class Solution {
    int n;
    vector<vector<int>> ans;
public:

    void backtrack(int first,vector<int>& nums,int num,vector<int>& path)
    {//num是，这一轮要求的子集的规模
        if(path.size()==num)
        {
            ans.push_back(path);
        }
        for(int i=first;i<n;i++)
        {//如果path没满，再从first之后的某个位置，添加一个元素
            path.push_back(nums[i]);
            backtrack(i+1,nums,num,path);//注意，这里放i+1,作用是，保证一个path里面的元素的
                                            //顺序，在原来nums里面的对应顺序是一样的。自动起到
                                            //去重的功能。
            path.pop_back();//准备迎接下一个候选nums[i]。
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        n=nums.size();
        //枚举元素数目i
        for(int i=0;i<=n;i++)
        {
            vector<int> path;//空的
            backtrack(0,nums,i,path);
        }

        return ans;
        }
    };
    
    class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void find(int dep, vector<int>& nums)
    {
        // 已经处理完最后一位，将目前存储的集合存入 ans ，并回溯
        if(dep <= 0)
        {
            ans.push_back(tmp);
            return;
        }
        // 情况一：集合中有该元素
        tmp.push_back(nums[dep - 1]);
        find(dep - 1, nums);
        tmp.pop_back();
        // 情况二：集合中无该元素
        find(dep - 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        find(nums.size(), nums);
        return ans;
    }
};


    class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        helper(res,tmp,nums,0);
        return res;
    }
    void helper(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,int level){
        if(tmp.size()<=nums.size()){
            res.push_back(tmp);
        }
        for(int i=level;i<nums.size();i++){
            tmp.push_back(nums[i]);
            helper(res,tmp,nums,i+1);
            tmp.pop_back();
        }
    }
};



下面的做法是利用了幂集的性质。第一次做不容易想出来。对照一个示例走一遍会更好理解。


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans;
        ans.push_back(vector<int>{});//空的，作为[[]]是最初状态

        vector<int> temp;

        //枚举nums的每个元素，加到ans的每个元素里面
        for(int i=0;i<nums.size();++i)
        {
            int sz=ans.size();
            for(int j=0;j<sz;++j)
            {
                temp=ans[j];//然后往temp里面加元素nums[i]
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。