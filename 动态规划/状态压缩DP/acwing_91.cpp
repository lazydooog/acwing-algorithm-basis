/*
* @Description: 91. 最短Hamilton路径
* @Author: Xiaobin Ren
* @Date:   2020-08-23 22:08:09
* @Last Modified time: 2020-08-23 22:08:16
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20, M = 1 << N ;
int w[N][N];
int f[M][N];  // f[i][j] 表示所有从0走到j 走过的所有点是二进制表示的i的路径

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    memset(f, 0x3f, sizeof f);        
    f[1][0] = 0; //最初是第0位 第0位的状态就是1
    for(int i = 0 ; i < 1 << n; i++)
        for(int j = 0; j < n; j++)
            if(i >> j & 1)
                for(int k = 0; k < n; k++) //枚举转移的点 也就是倒数第二个点
                    if((i - (1 << j)) >> k & 1) //要包含第k位
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    
    cout << f[(1 << n) - 1][n - 1] << endl;
                    
    return 0;
}