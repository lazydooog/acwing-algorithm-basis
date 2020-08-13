/*
* @Description: 858. Prim算法求最小生成树
* @Author: Xiaobin Ren
* @Date:   2020-08-13 20:02:53
* @Last Modified time: 2020-08-13 20:03:01
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int a[N][N], d[N], n, m, ans;

bool v[N];

void prim(){
    d[1] = 0;
    for(int i = 1; i < n; i++){ //循环 n - 1 次，默认选中第一个点 
        int x = 0;
        for(int j = 1; j <= n; j++)
            if(!v[j] && (x== 0 || d[j] < d[x]))  x = j;  //找到集合之外边权最小的点
        v[x] = 1;
        
        for(int y = 1; y <= n; y++)  //更新 点x 所有出边，
        //也就是更新另外一个集合到该集合的所有边权，直接扫一遍没有访问过的边
            if(!v[y]) d[y] = min(d[y], a[x][y]);
    }
}

int main(){
    memset(d, 0x3f, sizeof d);
    memset(v, 0, sizeof v);
    memset(a, 0x3f, sizeof a); //邻接矩阵注意初始化 a 和 d 数组，当然floyd 算法没有a数组
    
    cin >> n >> m;
    int x, y, z;
    
    for(int i = 1; i <= n; i++) a[i][i] = 0;
    
    while(m--){
        cin >> x >> y >> z;
        a[y][x] = a[x][y] = min(a[y][x], z);
    }
    
    prim();
    for(int i = 2; i <= n; i++) ans += d[i];  //n - 1条边的权值和
    
    if(ans > INF / 2) cout << "impossible" << endl;  //图不联通，但是有负边加上减小了无穷的值
    else cout << ans << endl;
    return 0;
}