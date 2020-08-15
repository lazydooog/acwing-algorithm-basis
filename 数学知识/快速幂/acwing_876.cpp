/*
* @Description: 876. 快速幂求逆元
* @Author: Xiaobin Ren
* @Date:   2020-08-15 18:57:04
* @Last Modified time: 2020-08-15 18:57:47
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;

ll qmi(ll a, ll b, int p){
    ll res = 1; a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    
    return res;
}
// 思路用费马小定理 如果 b p 互质， 且p为质数，那么b 模p的乘法逆元就是b^(p - 2)mod(p) 
int main(){
    cin >> n;
    int a, p;
    while(n--){
        cin >> a >> p;
        if(__gcd(a, p) != 1) cout << "impossible" <<endl;
        else cout << qmi(a, p -2 , p) << endl;
    }
    
    return 0;
}