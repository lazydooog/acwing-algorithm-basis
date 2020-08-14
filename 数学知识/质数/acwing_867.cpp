/*
* @Description: 867. 分解质因数
* @Author: Xiaobin Ren
* @Date:   2020-08-14 13:28:18
* @Last Modified time: 2020-08-14 13:28:27
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100010; // 数组开sqrt(N) 的数量级即可 看循环的次数
int p[N], c[N];

int n, m;
//复杂度 O(sqrt(n))
void divide(int n){
    m = 0;
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){ //i是质数
            p[++m] = i, c[m] = 0;
            while(n % i == 0) n /= i, c[m] ++;  // c记录幂次 p记录底数
        }
    }
    
    if(n > 1) p[++m] = n, c[m] = 1; //n本身是质数
    
    for(int i = 1; i <= m; i++){
        cout << p[i] << ' ' << c[i] << endl;
    }
    cout << endl;
}

int main(){
    int x;
    cin >> n;
    while(n --){
        cin >> x; 
        divide(x);
    }
    
    return 0;
}