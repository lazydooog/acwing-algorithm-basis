/*
* @Description: 900. 整数划分
* @Author: Xiaobin Ren
* @Date:   2020-08-22 19:48:06
* @Last Modified time: 2020-08-22 19:48:11
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010, M = 1e9 + 7;

//1 2 3 ...n  每个数字可以用无限次，加起来是N  完全背包  f[i][j] = f[i-1][j] + f[i][j - i] 可以继续一维优化
//f[i][j] 表示 选了i个数，加起来和是j

int n;
int f[N];

int main(){
    cin >> n;
    f[0] = 1;  //一个数都不选 是一种方案  
    
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) //j从i开始 是第二维的限制 数组下标>0 
            f[j] = (f[j] + f[j - i]) % M;
            
    cout << f[n] << endl;
    
    return 0;
}