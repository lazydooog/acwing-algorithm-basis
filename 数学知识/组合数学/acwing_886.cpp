/*
* @Description: 886. 求组合数 II (逆元)
* @Author: Xiaobin Ren
* @Date:   2020-08-16 18:24:21
* @Last Modified time: 2020-08-16 18:24:39
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
//递推复杂度O(n^2)  10000会超时 要用 逆元处理方法 
//1e9 + 7 是质数 所以可以用fermat 快速幂求逆元 复杂度 n * log n

const int N = 100010, mod = 1e9 + 7;

int fact[N], infact[N];  //阶乘和阶乘逆元 模 mod的值 预处理

int qmi(int a, int k, int p)    // 快速幂模板
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    
    int n;
    int a, b;
    cin >> n;
    
    fact[0] = infact[0] = 1;
    for(int i = 1; i <= N; i++){ //预处理
        fact[i] = 1ll * i * fact[i - 1] % mod;
        infact[i] = 1ll * infact[i -1] * qmi(i, mod - 2, mod) % mod;
    }
    

    while(n -- ){
        cin >> a >> b;
        cout << (1ll * fact[a] * infact[b]  % mod * infact[a - b]) % mod << endl;
    }
    
    return 0;
}
