每次沿着一个方向走，遇到边界或者已经遍历过时变换方向，时间复杂度为O(n*m)
向右（0,1）
向下（1,0）
向左（0，-1）
向上（-1,0）

使用dx记录第一列，使用dy记录第二列
用d来控制方向 d在0到3之间 即 d=(d+1)%4;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans; 
        vector<pair<int, int>> dirs = {{0, 1},{1, 0},{0, -1},{-1, 0}};
        int i = 0, j = -1, m = matrix.size() - 1, n = matrix[0].size(), dir = 0, loopTime;
        while(m >= 0 && n >= 0){
            loopTime = dir % 2 ? m-- : n--;
            for(int k = 0; k < loopTime; ++k){ //k就对应上文的遍历数量
                i += dirs[dir].first;
                j += dirs[dir].second;
                ans.push_back(matrix[i][j]);
            }
            dir = (dir + 1) % 4; 
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return {};
        int m=matrix[0].size();
        vector<int > res;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

        for(int x = 0,y=0,d = 0,k = 1;k<=n*m;k++){
            vis[x][y]=true;
            res.push_back(matrix[x][y]);
            int a= x+dx[d],b=y+dy[d];//a,b表示沿着当前方向行进的下一个位置
            if(a<0||b<0||a>=n||b>=m||vis[a][b]){//越过边界或者已经遍历过时变换方向
                d=(d+1)%4;//转变方向
                a= x+dx[d],b=y+dy[d];//重新计算a,b
            }
            x=a,y=b;
        }
        return res;
    }
};



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return  {};
        }
        int l=0,r=matrix[0].size()-1,t=0,b=matrix.size()-1,x=0;
        vector<int> ans((r+1)*(b+1),0);
        while(true){
            for(int i=l;i<=r;i++) ans[x++]=matrix[t][i];
            if(++t>b)break;
            for(int i=t;i<=b;i++) ans[x++]=matrix[i][r];
            if(l>--r)break;
            for(int i= r;i>=l;i--) ans[x++]=matrix[b][i];
            if(t>--b) break;
            for(int i=b;i>=t;i--) ans[x++]=matrix[i][l];
            if(++l>r)break;
        }
        return ans;
    }
};


思路：按顺序，上边，右边，下边，左边，遍历数字。
遍历结束条件：只要保证数字不重复，当扫描个数到达矩阵中元素个数时，结束。
遍历顺序：用top,bottom,left,right,圈定一个矩形框。按顺时针遍历矩形框，一定是按顺序的。

去重：先遍历上边和右边。遍历下边时，不要再遍历在上边已遍历过的数字。
遍历左边时，不要再遍历在右边已遍历过的数字。关键是保证不重复扫描。


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int R,C;
        if(!(R=matrix.size()) || !(C=matrix[0].size())){
            return ans;
        }

        int top=0,left=0,right=C-1,bottom=R-1;
        while(ans.size() < R*C){
            //遍历上边
            for(int i=left;i<=right;++i) ans.push_back(matrix[top][i]);
            //遍历右边
            for(int i=top+1;i<bottom;++i) ans.push_back(matrix[i][right]);
            //遍历下边
            for(int i=right;i>=left && bottom > top;--i) ans.push_back(matrix[bottom][i]);
            //遍历左边
            for(int i=bottom-1;i>top && left < right;--i) ans.push_back(matrix[i][left]);
            top++;bottom--;
            left++;right--;
        }
        return ans;
    }
};




