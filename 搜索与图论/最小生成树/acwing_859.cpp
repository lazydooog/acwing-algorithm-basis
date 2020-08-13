/*
* @Description: 859. Kruskal算法求最小生成树
* @Author: Xiaobin Ren
* @Date:   2020-08-13 21:18:03
* @Last Modified time: 2020-08-13 21:18:11
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;

//kruskal 不需要什么矩阵邻接表 直接结构体就可以了

int n, m; 
int p[N];  //并查集父亲节点

struct Edge{
    int a, b, w;
    bool operator< (const Edge &u) const{
        return w < u.w;
    }
}edges[M];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    
    cin >> n >> m;
    int a, b, x;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> x;
        edges[i] = {a, b ,x};
    }
    
    sort(edges, edges + m);
    
    for(int i = 1; i <= n; i++) p[i] = i;  //初始化并查集
    
    int res = 0, cnt = 0;  //res答案 cnt 记录当前加入的边数 最小生成树一共n - 1 条边
    
    for(int i = 0; i < m; i++){ //枚举所有的边
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        
        a = find(a), b = find(b);
        if(a != b){  //不连通 合并更新
            res += w;
            p[a] = b;
            cnt ++;  
        }
    }
    
    if(cnt < n - 1) cout << "impossible" << endl;
    else cout << res << endl;
    
    return 0;
}

