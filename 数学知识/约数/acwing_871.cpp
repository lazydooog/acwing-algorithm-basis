/*
* @Description: 871. 约数之和
* @Author: Xiaobin Ren
* @Date:   2020-08-14 22:46:39
* @Last Modified time: 2020-08-14 22:46:45
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main(){
    
    unordered_map<int ,int > primes;
    
    int n, x;
    cin >> n;
    while(n --){
        cin >> x;
        
        for(int i = 2; i <= x / i; i++)
            while(x % i == 0){
                x /= i;
                primes[i] ++;
            }
        if(x > 1) primes[x] ++;
    }
    
    ll res = 1;
    for(auto prime : primes){
        int p = prime.first,  a = prime.second;
        ll t = 1;  //等比数列求和 递推法
        while(a--) t = (t * p + 1) % mod;
        res  = res * t % mod;
    }
    
    cout << res << endl;
    
    return 0;
}

