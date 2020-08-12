/*
* @Description: 851. spfa求最短路
* @Author: Xiaobin Ren
* @Date:   2020-08-12 20:51:13
* @Last Modified time: 2020-08-12 20:51:18
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 100010;
int h[N], ne[M], idx,e[N], w[N], d[N];
bool v[N];
int n, m;
queue<int> q;

void add(int a, int b, int u){
    e[idx] = b;
    w[idx] = u;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void spfa(){
    d[1] = 0; v[1] = 1;  //在队列中就是1 不在就是0
    
    q.push(1);
    while(q.size()){
        int x = q.front(); q.pop();
        v[x] = 0;
        
        for(int i = h[x]; i != -1; i = ne[i]){
            int y = e[i]; int u = w[i];
            if(d[x] + u < d[y]){
                d[y] = d[x] + u;
                if(!v[y]) q.push(y), v[y] = 1;
            }
        }
    }
}

int main(){
    
    memset(h, -1, sizeof h);
    memset(v, 0, sizeof v);
    memset(d, 0x3f, sizeof d);
    
    cin >> n >> m;
    int a, b;
    int x;
    while(m --){
        cin >> a >> b >> x;
        add(a, b, x);
    }
    
    spfa();
    
    if(d[n] == 0x3f3f3f3f) cout << "impossible"  << endl;
    else cout << d[n] << endl;
    
    
    return 0;
}

