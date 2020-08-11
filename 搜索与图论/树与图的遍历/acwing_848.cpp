/*
* @Description: 848. 有向图的拓扑序列
* @Author: Xiaobin Ren
* @Date:   2020-08-11 15:16:20
* @Last Modified time: 2020-08-11 15:16:29
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;
int n, m;
const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], path[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool topsort(){
    for(int i = 1; i <= n; i++)
        if(d[i] == 0) q.push(i);
    
    int cnt = 0;
    while(q.size()){
        int t = q.front();
        path[cnt++] = t;
        //for(int i = 0; i < n; i++) cout << path[i] << ' '; cout << endl;
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(-- d[j] == 0) q.push(j);
        }
    }
    
    return cnt == n ;
}

int main(){
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    int a, b;
    while(m --){
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    
    if(topsort()){
        for(int i = 0; i < n; i++) cout << path[i] << ' ';
        cout << endl;
    }else cout << -1 << endl;
    
    return 0;
}