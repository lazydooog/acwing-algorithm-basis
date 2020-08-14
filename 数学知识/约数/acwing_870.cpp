/*
* @Description: 870. 约数个数
* @Author: Xiaobin Ren
* @Date:   2020-08-14 21:15:57
* @Last Modified time: 2020-08-14 21:16:07
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

//将每一个ai分解 然后把指数相加就是最后的乘积的质因数分解结果
//约数个数就是指数加1再相乘即可

int main(){
    int n;
    cin >> n;
    int x;
    
    unordered_map<int, int> primes;
    
    while(n --){
        cin >> x;
        
        for(int i = 2; i <= x / i; i++)
            while(x % i == 0){
                x /= i;
                primes[i] ++;
            }
            
            if(x > 1) primes[x] ++;
    }
    
    ll res  = 1;
    for(auto prime : primes) res = res*(prime.second + 1) % mod;
    
    cout << res <<endl;
    
    return 0;
}