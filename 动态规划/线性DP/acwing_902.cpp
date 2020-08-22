/*
* @Description: 902. 最短编辑距离
* @Author: Xiaobin Ren
* @Date:   2020-08-22 13:42:02
* @Last Modified time: 2020-08-22 13:42:11
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

int main(){
    
    cin >> n; cin >> a + 1;
    cin >> m; cin >> b + 1;
    
    //边界处理
    for(int i = 0; i <= m; i++) f[0][i] = i; //为0的情况下只能添加
    for(int i = 0; i <= n; i++) f[i][0] = i; //用一个全串 来匹配空串
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1 ); //增删
            if(a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);  //相同就不需要操作
            else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);  //不相同 就改
        }
    cout << f[n][m] << endl;
    
    
    return 0;
}