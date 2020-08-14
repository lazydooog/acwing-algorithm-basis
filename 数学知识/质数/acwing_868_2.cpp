/*
* @Description: 线性筛法
* @Author: Xiaobin Ren
* @Date:   2020-08-14 19:27:57
* @Last Modified time: 2020-08-14 19:28:08
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1000010;
int v[N], primes[N];

int primes_1(int n){ //埃氏筛 本质原理 每个数被筛的时候 都是质数的倍数在筛 合数已经被筛掉了
    int cnt = 0;
    memset(v, 0, sizeof v);
    for(int i = 2; i <= n; i++){
        if(v[i]) continue;  //没有被筛过 那就是质数
        cnt ++; //只有质数才会运行到这一步 i 此时就是质数
        for(int j = i; j <= n / i; j++) v[i * j] = 1;  //对于每个数x 从x^2 开始筛，因为小于x^2的x的倍数已经被标记过了
    }
    
    return cnt;
}

int primes_2(int n){  //线性筛法 在 N = 1e7 级别的时候 比埃氏筛快一倍
    memset(v, 0, sizeof v);
    int cnt = 0;
    for(int i = 2; i <=n ;i++){
        if(!v[i]) primes[cnt ++] = i;  //i还没有被筛过 说明为质数
        for(int j = 0; primes[j] <= n / i; j++){ // 枚举所有比i小的质数
            v[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
    
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << primes_2(n) << endl;
    
    return 0;
}