/*
* @Description: 850. Dijkstra求最短路 II
* @Author: Xiaobin Ren
* @Date:   2020-08-12 18:33:47
* @Last Modified time: 2020-08-12 18:33:55
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

//堆优化 dijkstra

const int N =150010, M = 150010;
int h[N], e[M], ne[M], w[M], d[N], idx;
bool v[N];  //是否被访问过 该节点
int n, m;

priority_queue<pii , vector<pii>, greater<pii> > q; //第一维度是dist  第二维是节点编号 pair默认按照第一维排序

void add(int a, int b, int u){
    e[idx] = b;
    w[idx] = u;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dijkstra(){
    d[1] = 0;
    q.push({0, 1});  //初始化第一个节点 距离为0

    while(q.size()){
        int x = q.top().second; q.pop();
        if(v[x]) continue;
        v[x] = 1;
        for(int i = h[x]; i != -1; i = ne[i]){
            int y = e[i], u = w[i];
            if(d[y] > d[x] + u){
                d[y] = d[x] + u;
                q.push({d[y], y});
            }
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
