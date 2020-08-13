/*
* @Description: 854. Floyd求最短路
* @Author: Xiaobin Ren
* @Date:   2020-08-13 17:38:03
* @Last Modified time: 2020-08-13 17:38:10
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int  N = 210, INF = 1e9;
int n, m , k;
int d[N][N];  

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
     cin >> n>> m >> k;
     
     for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
     
    int a , b , x;
    while(m --){
      cin >> a >> b >> x;
      d[a][b] = min(d[a][b], x); //判断重边
    }
    
    floyd();
    
    while(k--){
        cin >> a >> b;
        if(d[a][b] > INF / 2)  cout << "impossible" << endl; //即使没有路径 也可能会把无穷给更新 不能判断==INF
        else cout << d[a][b] << endl;
    }
    
    return 0;
}