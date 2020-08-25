/*
* @Description: 905. 区间选点
* @Author: Xiaobin Ren
* @Date:   2020-08-25 21:50:36
* @Last Modified time: 2020-08-25 21:50:43
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000010;
int n;

struct Range{
    int l, r;
    bool operator< (const Range &W)const{
        return r < W.r;
    }
}range[N];

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l ,r};
        
    }
    sort(range, range + n);
    
    int res = 0, ed = -2e9;  //上一个区间的右端点
    
    for(int i = 0; i < n; i++)
        if(range[i].l > ed){
            res ++;
            ed = range[i].r;
        }
    cout << res << endl;
    
    return 0;
}