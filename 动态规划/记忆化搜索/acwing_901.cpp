/*
* @Description: 901. 滑雪
* @Author: Xiaobin Ren
* @Date:   2020-08-23 23:52:38
* @Last Modified time: 2020-08-23 23:52:45
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 310;

int n, m;
int h[N][N];
int f[N][N];  // f[i][j]  表示h[i][j] 为起点的最长路径长度

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y){
    int &v = f[x][y];  //用v表示状态 引用 来更新 f[x][y]
    if(v != -1) return v;
    
    v = 1; //每次递归时候 当前位置都置为1 是因为 当前的结果+1 返回给上一级 加上 才是上一层递归的结果
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
            v = max(v, dp(a, b) + 1);
    }
    
    return v;
}

int main(){
    
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j =1; j <= m; j++)
            cin >> h[i][j];
            
    memset(f, -1, sizeof f); //初始化为 - 1 代表还没有算过
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            res = max(res ,dp(i, j));
            
    cout << res << endl;
    
    return 0;
}