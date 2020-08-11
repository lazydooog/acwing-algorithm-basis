/*
* @Description: 846. 树的重心
* @Author: Xiaobin Ren
* @Date:   2020-08-11 13:08:37
* @Last Modified time: 2020-08-11 13:08:45
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans = 0x3f3f3f3f;
const int N = 100010;
int e[2 * N], ne[2 * N], h[N], idx;
int v[N]; //记忆化
int pos;  //最终答案
int sz[N];  //每个节点为根的子树的大小
int n; 

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int x){
    v[x] = 1;
    sz[x] = 1;
    int maxpart = 0;  //删掉x后分成的最大子树的大小
    for(int i = h[x]; i != -1; i = ne[i]){
        int y = e[i];
        if(v[y]) continue;
        dfs(y);
        sz[x] += sz[y];
        maxpart = max(maxpart, sz[y]);
    }
    
    maxpart = max(maxpart, n - sz[x]);
    if(maxpart < ans){
        ans = maxpart;
        pos = x; //重心位置
    }
}

int main(){
    int a, b;
    cin >> n;
    memset(h, -1 ,sizeof h); //切记初始化要在加边之前
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    
    dfs(1);
    cout << ans << endl;
    return 0;
}
