/*
* @Description: 898. 数字三角形
* @Author: Xiaobin Ren
* @Date:   2020-08-20 22:36:23
* @Last Modified time: 2020-08-20 22:36:31
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510;
const int INF = 1e9;  //处理边界
int a[N][N], f[N][N];
//复杂度 = 状态数量 * 转移所需复杂度 本题为 n^2 * 1

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
            
    memset(f, 0xcf, sizeof f); //将f全部初始化为－无穷
            
    f[1][1] = a[1][1];
    
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++){
            f[i][j] = f[i - 1][j] + a[i][j];
            if(j > 1) f[i][j] = a[i][j] + max(f[i -1][j], f[i - 1][j - 1]);
        }
            
    
    int res = -INF;
    for(int i = 1; i <= n; i++) 
        res = max(res, f[n][i]);
            
    cout << res << endl;            

    return 0;
}