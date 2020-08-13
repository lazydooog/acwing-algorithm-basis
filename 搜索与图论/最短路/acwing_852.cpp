/*
* @Description: 852. spfa判断负环
* @Author: Xiaobin Ren
* @Date:   2020-08-13 11:57:33
* @Last Modified time: 2020-08-13 11:57:43
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 2010, M = 10010;
int h[N], ne[M], idx, d[N], w[N],e[M];
bool v[N];


queue<int> q;
int cnt[N]; //cnt记录某个点到n号点的路径个数 不是路径长度
int n, m;


void add(int a, int b, int u){
    e[idx] = b;
    w[idx] = u;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa(){
    //由于求整个图 而不是只求1号开始到其他点的路径否有负环，所以初始把所有点都加入队列
    
    for(int i = 1; i <= n; i++) q.push(i), v[i] = 1;
    
    while(q.size()){
        
        int x= q.front(); q.pop();
        v[x] = 0;

        for(int i = h[x]; i != -1; i = ne[i]){
            int y = e[i];
            if(d[y] > d[x] + w[i]){
                d[y] = d[x] + w[i];
                cnt[y] = cnt[x] + 1; //更新路径之后 三角形不等式，然后边数加一
                if(cnt[y] >= n) return true; // n个点 无环路径最多 n - 1 条边 
                if(!v[y]) q.push(y), v[y] = 1;
            }
        }
    }
    
    return false;
}

int main(){
    
    memset(h, -1, sizeof h);
    memset(v, 0, sizeof v);
    memset(d, 0x3f, sizeof d);
    
    int a, b , x;

    cin >> n >> m;
    while(m --){
        cin >> a >> b >> x;
        add(a, b, x);
    }
    
    spfa();
    if(spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;    
}
