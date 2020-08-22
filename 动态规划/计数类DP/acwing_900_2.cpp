/*
* @Description: 900. 整数划分
* @Author: Xiaobin Ren
* @Date:   2020-08-22 20:18:51
* @Last Modified time: 2020-08-22 20:18:57
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010, M = 1e9 + 7;

//整数划分 第二种 思路；
//f[i][j] 表示 总和是i 用了j个数相加起来 得到了N  的 所有方案数
//分为两类 一种是 这j个数 中最小值是1， 另外一种是 最小值大于1 
// f[i][j] = f[i - 1][j-1] + f[i - j][j]  第一项是把开头的1去掉 第二项是 j个数 每个都减去1 
//最后的答案 ans = f[n][1] + f[n][2] + ..... f[n][n]

int n;
int f[N][N];

int main(){
    cin >> n;
    
    f[0][0] = 1;
    
    for(int i = 1; i <= n;i++)
        for(int j= 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % M;
    
    int res = 0;
    
    for(int i = 1; i <= n; i++) res = (res + f[n][i]) % M;
    
    cout << res  << endl;
    
    return 0;
}

