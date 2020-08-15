/*
* @Description: 874. 筛法求欧拉函数
* @Author: Xiaobin Ren
* @Date:   2020-08-15 13:36:19
* @Last Modified time: 2020-08-15 13:36:39
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000010;

int n;
int primes[N], cnt;
int phi[N]; //欧拉函数
bool v[N];

long long get_euler(int n){ //线性筛求欧拉函数 O(N)
    phi[1] = 1;
    for(int i = 2; i <=n; i++){
        if (!v[i]){
            primes[cnt++] = i;
            phi[i] = i -1;
        }
        for(int j = 0; primes[j] <= n / i; j++){
            int t = primes[j] * i;
            v[t] = 1;
            if(i % primes[j] == 0){
                phi[t] = phi[i] * primes[j];
                break;
            }else phi[t] = phi[i] * (primes[j] - 1);
        }
    }
    long long res = 0; //最坏情况下质数phi[n] = n - 1 答案是n^2 级别的 要用long long
    for(int i = 1; i <= n; i++) res += phi[i];
    return res;
}

int main(){
    cin >> n;
    cout << get_euler(n) << endl;
    
    return 0;
}