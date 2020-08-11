/*
* @Description: 847. 图中点的层次
* @Author: Xiaobin Ren
* @Date:   2020-08-11 14:50:54
* @Last Modified time: 2020-08-11 14:51:04
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;  //有向图 边和点开一样就可以了
int e[N], ne[N], h[N], idx;
int n, m;
int d[N], q[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs(){
    int hh = 0, tt = 0;
    q[0] = 1; //初始化队头
    memset(d, -1, sizeof d);  //-1表示没有被遍历过
    d[1] = 0; 
    
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[n];
}


int main(){
    
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    while(m --){
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs() << endl;
    
    return 0;
}