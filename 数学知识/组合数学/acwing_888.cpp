/*
* @Description: 888. 求组合数 IV
* @Author: Xiaobin Ren
* @Date:   2020-08-17 16:04:01
* @Last Modified time: 2020-08-17 16:04:07
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//对于不是取模 而且 数很大的话 要用分解质因数

const int N = 5010;

int primes[N], cnt;
int sum[N]; 
bool st[N];

int p;

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}

int get(int n){  //求出 n！ 中包含的p的个数
    int res = 0;
    while(n){
        res += n / p;
        n /= p;
    }
    
    return res;
}

vector<int> mul(vector<int> &a, int b){
    vector<int> c;
    int t = 0;
    for(int i= 0; i <a.size(); i++){
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    
    return c;
}

int main(){
    int a, b;
    cin >> a>> b;
    get_primes(a);  //求出1 ~ a 中所有质数
    
    for(int i = 0; i < cnt; i++){
        p = primes[i];
        sum[i] = get(a) - get(b) - get(a - b); //整个组合数计算除式中的p的次数 0就相当于不减
    }
    
    vector<int> res;  //高精度乘法
    res.push_back(1);
    for(int i = 0; i < cnt; i++)
        for(int j = 0; j < sum[i]; j++)  //计算次数
            res = mul(res, primes[i]);
    for(int i = res.size() -1 ; i >= 0; i--) cout << res[i];
    cout << endl;
    
    return 0;
    
}