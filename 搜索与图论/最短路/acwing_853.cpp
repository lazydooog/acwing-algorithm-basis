/*
* @Description: 
* @Author: Xiaobin Ren
* @Date:   2020-08-13 11:07:15
* @Last Modified time: 2020-08-13 11:07:32
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 510, M = 10010;
int h[N], ne[M], idx,e[N], w[N], dist[N];
bool v[N];
int n, m, k;


int backup[N];

//有边数限制 只能用bellman ford 算法，同时由于边数限制 负环也就无意义了
//bellman ford 算法迭代k次 求出的d数组 代表k条边能到达的最短路

struct Edge{
    int a, b , w;  
}edges[M];



int bellmanford(){
    
    dist[1] = 0;
    
    for(int i = 0; i < k; i++){ //迭代k次
        memcpy(backup, dist, sizeof dist); //记录上一次迭代的结果 防止迭代时发生边的串连 
        for(int j = 0; j < m; j++){
            int a = edges[j].a, b = edges[j].b, u =edges[j].w;
            dist[b] = min(dist[b], backup[a] + u);  //利用backup
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1; //不能写成 dist[n] == 0x3f3f3f3f 即使不存在但是会被更新，不等于无穷了
    else return dist[n];
}

int main(){
    
    memset(dist, 0x3f, sizeof dist);
    
    cin >> n >> m >> k;
    int x;
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >>b >> w;
        edges[i] = {a, b, w};
    }
    
    int t = bellmanford();
    if(t == -1) puts("impossible");
    else cout << t << endl;
    
    
    return 0;
}

