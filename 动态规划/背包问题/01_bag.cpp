/*
* @Description: 一维优化01背包
* @Author: Xiaobin Ren
* @Date:   2020-08-19 20:20:22
* @Last Modified time: 2020-08-19 20:20:50
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//01背包 每件物品 最多用一次 也就是用1次 或者0次

const int N = 1010;
int n, m;   //m表示背包的容积
int v[N], w[N];
int f[N];

int main(){
    cin >> n>> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = m; j >=v[i]; j--){  //这里的j <= m  就保证了决策的边界 一定不会超出背包容积

            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    cout << f[m] << endl;
    
    return 0;
}