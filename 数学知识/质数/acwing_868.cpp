/*
* @Description: 868. 筛质数(优化埃拉托色尼斯筛法)
* @Author: Xiaobin Ren
* @Date:   2020-08-14 17:48:46
* @Last Modified time: 2020-08-14 17:49:11
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1000010;
int v[N];

int primes(int n){
    int cnt = 0;
    memset(v, 0, sizeof v);
    for(int i = 2; i <= n; i++){
        if(v[i]) continue;  //没有被筛过 那就是质数
        cnt ++;
        for(int j = i; j <= n / i; j++) v[i * j] = 1;  //对于每个数x 从x^2 开始筛，因为小于x^2的x的倍数已经被标记过了
    }
    
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << primes(n) << endl;
    
    return 0;
}