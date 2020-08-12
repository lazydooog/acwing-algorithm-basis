/*
* @Description: 849. Dijkstra求最短路 I
* @Author: Xiaobin Ren
* @Date:   2020-08-12 14:54:48
* @Last Modified time: 2020-08-12 14:55:01
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;
int h[N], e[M], ne[M], w[M], d[N], idx;
bool v[N];  //是否被访问过 该节点
int n, m;

void add(int a, int b, int u){
    e[idx] = b;
    w[idx] = u;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dijkstra(){
    d[1] = 0;
    for(int i = 1; i < n; i++){ // 循环n - 1 次数
        int x = 0;
        for(int j = 1; j <= n; j++)  //求出当前dist 最小的点
            if(!v[j] && (x == 0 || d[j] < d[x])) x = j;
        v[x] = 1;  //标记访问
        
        //更新其他点
        for(int i = h[x]; i != -1; i = ne[i]){
            int y = e[i];
            d[y] = min(d[y], d[x] + w[i]);
        }
    }
}

int main(){
    memset(h, -1 ,sizeof h);
    memset(d, 0x3f , sizeof d);
    memset(v, 0, sizeof v);
    
    cin >> n >> m;
    int a, b, x;
    while(m--){
        cin >> a >> b >> x;
        add(a, b, x);
    }
    
    dijkstra();
    
    if(d[n] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << d[n] << endl;
    
    return 0;
}