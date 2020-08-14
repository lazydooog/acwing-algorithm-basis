/*
* @Description: 866. 试除法判定质数
* @Author: Xiaobin Ren
* @Date:   2020-08-14 11:40:14
* @Last Modified time: 2020-08-14 11:40:20
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    return true;
}

int main(){
    cin >> n;
    int a;
    while(n --){
        cin >> a;
        if(is_prime(a)) cout <<"Yes" << endl;
        else cout << "No" <<endl;
    }
    
    return 0;
}