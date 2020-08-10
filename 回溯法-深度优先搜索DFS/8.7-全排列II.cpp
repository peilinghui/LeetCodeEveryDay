nums记录当前排列数组；
ans记录每组返回；
len记录输入数组长度。

主函数，更新len及nums数组，并开始回溯

回溯函数，输入值为将要排列元素在的位置
1.递归出口为已经排列到len位置，即超出数组范围，这意味着已经完成了排列，将此排列并入答案集合。
2.temp数组记录每次排列所选择的数字。
3.n以前为已经定下的数字，n以后为待确定数字。
i为待选择数字，从第n位开始选取，待选位为nums[n]至nums[len-1]。
每次选择下一位数字，就应该把该数字置于当前的n位，可以通过swap（n，i）实现，wap之后当前的n位已经确定，接着调用dfs（n+1），开始确定下一位数字。
4.回溯，完成i位置数字选择调用后，再次swap（n，i），这样数组状态就和选择
5.剪肢，每次选择一个数字之后，都在temp数组记录已经选择过的数字（产生同解的本质原因恰恰是同一位在两次选择中选择的数字相等），对于在该位置已经选过的数字，不再选择。

代码

class Solution {
    vector<int> nums;//记录每一次选择后数组状态，包括最终答案
    vector<vector<int>> ans;//选择完每一个数组后并入答案集
    int len;//输入数组元素数量
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len=nums.size();//更新len
        this->nums=nums;//更新nums
        dfs(0);//开始回溯
        return ans;
    }
    void dfs(int n){
        if(n==len){
            ans.push_back(nums);//已经排列到len位置，即超出数组范围，这意味着已经完成了排列，将此排列并入答案集合
            return;
        }
        vector<int> temp={};//记录该位选择过的元素值，已经选择过的值不再选择
        for(int i=n;i<len;++i){//n为当前正在选择的位，i为准备要作为n位元素目前的位置
            if(find(temp.begin(),temp.end(),nums[i])!=temp.end())continue;//已经选择过的值不再选择
            swap(nums[n],nums[i]);//将第i位数字移动到n位，完成该位选择
            temp.push_back(nums[n]);//记录选择，防止选择相等数字产生多余的解
            dfs(n+1);//选择下一位数字
            swap(nums[n],nums[i]);//变为选择之前的状态，重新选择下一位数字
        }
    }
};

