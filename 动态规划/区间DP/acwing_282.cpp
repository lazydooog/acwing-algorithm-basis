/*
* @Description: 282. 石子合并
* @Author: Xiaobin Ren
* @Date:   2020-08-21 23:47:32
* @Last Modified time: 2020-08-21 23:47:40
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int a[N], f[N][N];
int sum[N];

int main(){
    
    memset(f, 0x3f, sizeof f);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){ //前缀和
        f[i][i] = 0;
        sum[i] = sum[i - 1] + a[i];
    }
    
    for(int len = 2; len <= n; len++) //枚举阶段
        for(int l = 1; l <= n - len + 1;  l++){
            int r = l + len - 1;
            for(int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);  //只需要枚举k的位置 然后求出最小的分割
            f[l][r] += sum[r] - sum[l - 1]; //最后加上的前缀和 都是一样的 所以没必要在枚举k的时候加上
        }
    
    cout << f[1][n] << endl;
    
    return 0;
}