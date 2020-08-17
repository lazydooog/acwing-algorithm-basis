/*
* @Description: 
* @Author: Xiaobin Ren
* @Date:   2020-08-17 16:18:35
* @Last Modified time: 2020-08-17 16:27:16
*/
#include <iostream>
#include <algorithm>
//#pragma GCC optimize(2)
using namespace std;
const int p = 1e9 + 7;
typedef long long ll;

// lucas求组合数 + 逆元 处理除法 


ll qmi(ll a, ll b, int p){
    ll res =1; a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
        
    }
    return res;
}

ll c(ll a, ll b){  //逆元求组合c(a, b)  这里注意 a,b传进来的都是对p取模之后的 所以一定会满足bp互质 逆元存在，可以费马小定理
    ll res = 1;
    for(ll i = 1, j = a; i <= b; i++, j --){
        res = res * j % p;
        res = res * qmi(i, p - 2, p) % p;
    }
    
    return res;
}

ll lucas(ll a, ll b){ //递归求lucas
    if(a < p && b < p) return c(a, b);
    return c(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main(){
    int n; cin >> n;
    cout << lucas(2 * n, n) % p * qmi(n + 1, p - 2, p) % p<< endl;
    return 0;
}