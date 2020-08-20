/*
* @Description: 895. 最长上升子序列
* @Author: Xiaobin Ren
* @Date:   2020-08-20 23:44:22
* @Last Modified time: 2020-08-20 23:44:28
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;

int a[N], f[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        f[i] = 1;  //只有a[i] 一个数的情况
        for(int j = 1; j < i; j++)
            if(a[j] < a[i]) 
                f[i] = max(f[i], f[j] + 1);
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    
    cout << res << endl;
    
    
    return 0;
}