/*
* @Description: 2. 01背包问题
* @Author: Xiaobin Ren
* @Date:   2020-08-19 16:47:35
* @Last Modified time: 2020-08-19 16:47:43
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//01背包 每件物品 最多用一次 也就是用1次 或者0次

const int N = 1010;
int n, m;   //m表示背包的容积
int v[N], w[N];
int f[N][N];

int main(){
    cin >> n>> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++){  //这里的j <= m  就保证了决策的边界 一定不会超出背包容积
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i-1][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
    
    return 0;
}