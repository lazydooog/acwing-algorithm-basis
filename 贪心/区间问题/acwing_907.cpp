/*
* @Description: 907. 区间覆盖
* @Author: Xiaobin Ren
* @Date:   2020-08-26 14:22:58
* @Last Modified time: 2020-08-26 14:23:08
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

//所有区间左端点排序 然后依次枚举所有区间 假设要覆盖的区间端点是start和end
//在能覆盖start的所有区间中 选择 右端点最大的区间 然后将start更新为右端点的最大值 

struct range{
    int l, r;
    bool operator< (const range & w)const {
        return l < w.l;
    }
}ranges[N];

int main(){
    int n;
    int s, t;
    cin >> s >> t;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l ,r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    sort(ranges, ranges + n);
    
    int res = 0;
    bool flag = 0;
    for(int i = 0 ; i < n; i++){  //双指针扫描
        int j = i, r = - 2e9;  //r是右端点最大值
        while(j < n && ranges[j].l <= s){
            r = max(r, ranges[j].r);
            j++;
        }
        if(r < s){  // 如果比s小的区间的左端点的 的右端点 也比s小 则连左端点都覆盖不了 直接 break
            res = -1;
            break;
        }
        res ++;  
        if(r >= t){
            flag = true;
            break;
        }
        s = r;
        i = j - 1; //更新双指针 继续扫描 i是扣住上一个区间 然后j扫描后边的区间
    }
    if(!flag) res = -1;
    cout << res << endl;
    
    return 0;
}