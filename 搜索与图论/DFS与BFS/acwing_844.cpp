/*
* @Description: 844. 走迷宫
* @Author: Xiaobin Ren
* @Date:   2020-08-11 09:45:38
* @Last Modified time: 2020-08-11 10:19:40
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
//所有边权都是一样的时候 才能用bfs求最短路
const int N = 110;
int g[N][N];
int d[N][N]; //每一个点到起点的距离 也就是bfs搜索的层次
pii q[N * N];  //手写队列
int n, m;

int bfs(){
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    memset(d, -1 ,sizeof d);
    d[0][0] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while(hh <= tt){
        auto t  = q[hh++];  //队头拿出 直接出队
        for(int i = 0; i < 4; i++){ //遍历上下左右四个方向的点 然后判断 入队
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }
    
    //bfs的性质可知 搜到的一定是最短的 不需要判断 直接输出结果就可以

    return d[n - 1][m - 1] ;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    
    cout << bfs() << endl;
    
    return 0;
}