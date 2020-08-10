/*
* @Description: 843. n-皇后问题 另外一种搜索 指数级别复杂度
* @Author: Xiaobin Ren
* @Date:   2020-08-10 20:54:53
* @Last Modified time: 2020-08-10 20:55:23
*/
#include <iostream>
using namespace std;

const int N = 20;  //记录对角线正反 所以开2倍数组
int n;

char g[N][N];  //答案
bool row [N], col[N], dg[N], udg[N];  //dg 对角线 udg 反对角线

void dfs(int x, int y, int s){  //x表示自上而下的行 y从左到右的列
    if (y == n) y = 0, x++;  //到行尾就下一行
    if(x == n){  //出界了 就搜索结束。  x是0 ~ n - 1
        if(s == n){
            for(int i = 0; i < n; i++) puts(g[i]);
            cout << endl;
        }
        return ;
    }
    
    //不放皇后 该格子
    dfs(x, y + 1, s);
    
    //放皇后
    // y = x + b => b = y - x;  x = -y, y = x => b = x + y;
    // y = - x + b + n -> b = x + y - n -> b = x - y - n ???? 为什么和结论不一样呢?
    if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]){
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        
        dfs(x, y + 1, s + 1);
        
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
            
    dfs(0, 0 ,0); //参数是坐标 第三维表示一共有多少个皇后
    
    return 0;
}
