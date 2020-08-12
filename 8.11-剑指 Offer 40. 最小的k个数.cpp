class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) vec[i] = arr[i];
        return vec;
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        if(k==0){
            return {};
        }
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }
};


我们用一个大根堆实时维护数组的前 kk 小值。
首先将前 kk 个数插入大根堆中，随后从第 k+1k+1 个数开始遍历，
如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，再插入当前遍历到的数。
最后将大根堆里的数存入数组返回即可。在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。


public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) return vec; // 排除 0 的情况
        priority_queue<int>Q;
        for (int i = 0; i < k; ++i) Q.push(arr[i]);
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0){
            return res;
        }
        priority_queue<int> h;
        for(int num : arr){
            if(h.size() < k){
                h.push(num);
            }else{
                if(h.top() <= num){
                    continue;
                }else{
                    h.pop();
                    h.push(num);
                }
            }
        }
        while(!h.empty()){
            res.push_back(h.top());
            h.pop();
        }
        return res;
    }
};

