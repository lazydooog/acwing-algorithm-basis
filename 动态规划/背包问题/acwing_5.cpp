/*
* @Description: 5. 多重背包问题 II
* @Author: Xiaobin Ren
* @Date:   2020-08-20 21:02:01
* @Last Modified time: 2020-08-20 21:02:09
*/
#include <iostream>
using namespace std;

//数据范围增大 不能暴力

const int N = 25000;  //数组开 N * log V
int v[N], w[N];
int f[N];
int n, m;

int main(){
    cin >> n >> m;
    
    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0){
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;
    
    for(int i = 1; i <= n; i++)  //当作普通01背包处理一遍即可
        for(int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
    
    return 0;
}

