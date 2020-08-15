/*
* @Description: 875. 快速幂
* @Author: Xiaobin Ren
* @Date:   2020-08-15 13:50:29
* @Last Modified time: 2020-08-15 13:50:35
*/
#include <iostream>
using namespace std;

typedef long long ll;
int n, a, b, p;

ll qmi(ll a, ll b, int p){
    ll res = 1; a %= p;
    while(b){
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

int main(){
    
    cin >> n;
    while(n--){
        cin >> a  >> b >> p;
        cout << qmi(a, b ,p) << endl;
    }
    
    return 0;
}