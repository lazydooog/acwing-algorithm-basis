/*
* @Description: 4. 多重背包问题 I
* @Author: Xiaobin Ren
* @Date:   2020-08-19 23:14:42
* @Last Modified time: 2020-08-19 23:14:50
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int v[N], w[N], s[N];
int f[N][N];

int n, m;

int main(){  //仿照完全背包的暴力法 每一类物品枚举k个 依次尝试
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i -1][j - v[i] * k] + k * w[i]);
    cout << f[n][m] << endl;
    
    return 0;
}
