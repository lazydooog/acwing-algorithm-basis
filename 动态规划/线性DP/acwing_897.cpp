/*
* @Description: 897. 最长公共子序列
* @Author: Xiaobin Ren
* @Date:   2020-08-21 21:05:17
* @Last Modified time: 2020-08-21 21:14:42
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
//f[i][j]  表示在a系列的前i个字母 和b序列的前j个字母中出现的子序列的最大长度
int n, m;
char a[N], b[N];
int f[N][N];

int main(){
    
    cin >> n >> m;
    cin >> a + 1 >> b + 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
        
    cout << f[n][m] << endl;
    return 0;
}