/*
* @Description: 285. 没有上司的舞会
* @Author: Xiaobin Ren
* @Date:   2020-08-23 22:58:34
* @Last Modified time: 2020-08-23 22:58:56
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 6010;

int n;
int happy[N];
int h[N], e[N], ne[N], idx;
bool has_father[N];

int f[N][2];  //f[u][0] 表示u为根的子树 不包含u节点的最大期望 f[u][1] 表示包含根节点u的子树的最大期望 


//从根节点开始递归求出 子树的期望 然后讨论 2种 包含根节点和不包含根节点的 值 取max即可

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u){
    f[u][1] = happy[u];
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        dfs(j);
        
        f[u][0] += max(f[j][0], f[j][1]);  //不选根节点 则子节点可选可不选
        f[u][1] += f[j][0];  //选了根节点 则子节点都不能选
    }
}

int main(){
    memset(h, -1, sizeof h);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> happy[i];
    
    for(int i = 0 ;i < n - 1; i++){  //加边
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_father[a] = true;
    }
    
    int root = 1;
    while(has_father[root]) root ++;  //求出根节点 就是没有父节点的 节点
    
    dfs(root);
    
    cout << max(f[root][0], f[root][1]) << endl;
    
    return 0;
}