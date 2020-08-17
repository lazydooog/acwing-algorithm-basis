/*
* @Description: 887. 求组合数 III
* @Author: Xiaobin Ren
* @Date:   2020-08-17 14:00:16
* @Last Modified time: 2020-08-17 14:00:25
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int p;
// lucas 定理降次 + 预处理 + 逆元


ll qmi(ll a, ll b){
    ll res =1; a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
        
    }
    return res;
}

ll c(ll a, ll b){  //逆元求组合c(a, b)
    ll res = 1;
    for(ll i = 1, j = a; i <= b; i++, j --){
        res = res * j % p;
        res = res * qmi(i, p - 2) % p;
    }
    
    return res;
}

ll lucas(ll a, ll b){ //递归求lucas
    if(a < p && b < p) return c(a, b);
    return c(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main(){
    int n; cin >> n;
    ll a, b;
    while(n--){
      cin >> a >> b >> p;
      cout << lucas(a, b) << endl;
    }
    
    return 0;
}