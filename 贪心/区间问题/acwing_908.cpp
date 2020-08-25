/*
* @Description: 908. 最大不相交区间数量
* @Author: Xiaobin Ren
* @Date:   2020-08-25 22:38:32
* @Last Modified time: 2020-08-25 22:38:39
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
int n;
struct Range{
    int l, r;
    bool operator< (const Range & w)const{
        return r < w.r;
    }
}range[N];

//选课问题 选结束时间最早的  和上一题 区间选点 完全一致的代码
int main(){
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l,r};
    }
    sort(range, range + n);
    
    int res = 0, ed = -2e9;
    for(int i = 0 ; i < n; i++)
        if(ed < range[i].l){
            res ++;
            ed = range[i].r;
        }
    
    cout << res << endl;
    
    return 0;
}