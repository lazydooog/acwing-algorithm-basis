/*
* @Description: 3. 完全背包问题
* @Author: Xiaobin Ren
* @Date:   2020-08-19 22:46:40
* @Last Modified time: 2020-08-19 22:47:22
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//01背包状态转移方程：f[i, j] = max(f[i - 1, j], f[i-1, j - v[i]] + w[i])
//完全背包状态转移方程 f[i, j] = max(f[i-1, j], f[i, j - v[i]] + w[i])
//两者区别 仅仅在于 是不同阶段之间的转移 还是相同阶段之间的转移 

const int N = 1010;
int v[N], w[N];
int f[N];  
int n, m;

int main(){ //一维优化
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = v[i]; j <= m; j++){
            if(v[i] <= j) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    
    cout << f[m] << endl;
    
    return 0;
            
}