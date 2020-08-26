/*
* @Description: 906. 区间分组
* @Author: Xiaobin Ren
* @Date:   2020-08-26 13:35:23
* @Last Modified time: 2020-08-26 13:35:29
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue> //小根堆 存储每一个组的最后一个右端点 最小的右端点
using namespace std;
const int N = 100010;
//按照左端点排序 如果能放进去 就放 如果左端点比所有组的最后一个右端点都小 则不能放进现在的组 就开新组

struct Range{
    int l, r;
    bool operator< (const Range & w)const {
        return l < w.l;
    }
}range[N];

int main(){
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l ,r};
    }
    sort(range, range + n);
    
    priority_queue<int, vector<int> , greater<int> > heap;
    
    for(int i = 0 ; i  < n; i++){
        auto r = range[i];  //处理每一个区间
        if(heap.empty() || heap.top() >= r.l) heap.push(r.r);  //加入新组
        else {  //否则放入已有的组中 就放入堆顶的组中 然后更新最小右端点 就是增大最小的右端点
            int t = heap.top();
            heap.pop();
            heap.push(r.r);
        }
    }
    
    cout << heap.size() << endl;
    
    return 0;
}