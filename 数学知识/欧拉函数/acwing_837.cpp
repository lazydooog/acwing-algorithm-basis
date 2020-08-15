/*
* @Description: 873. 欧拉函数
* @Author: Xiaobin Ren
* @Date:   2020-08-15 11:44:22
* @Last Modified time: 2020-08-15 11:44:28
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int phi(int n){
    int ans  =  n;
    for(int i = 2; i <= n / i; i++)
        if(n % i == 0){
            ans = ans / i *( i - 1);
            while(n % i == 0) n /= i;
        }
    if(n > 1) ans = ans / n * ( n - 1);  //n是质数就直接乘上就好了
    
    
    return ans;
}

int main(){
    cin >> n;
    int x;
    while(n--){
        cin >> x;
        cout << phi(x) << endl;
    }
    
    return 0;
}