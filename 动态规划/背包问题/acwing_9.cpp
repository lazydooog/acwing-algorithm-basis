/*
* @Description: 9. 分组背包问题
* @Author: Xiaobin Ren
* @Date:   2020-08-20 21:27:38
* @Last Modified time: 2020-08-20 21:27:46
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int v[N][N], w[N][N], s[N];
int n, m;
int f[N];

int main(){
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        for(int j = 0; j < s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = m ;j >= 0; j--)
            for(int k = 0; k < s[i]; k++)
                if(j >= v[i][k]) // 对体积在内层循环再特判 上边j直接就是 枚举到0即可 和01背包不一样
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    
    cout << f[m] << endl;
        
    return 0;
}