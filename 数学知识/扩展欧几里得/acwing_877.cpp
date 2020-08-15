/*
* @Description: 877. 扩展欧几里得算法
* @Author: Xiaobin Ren
* @Date:   2020-08-15 19:40:59
* @Last Modified time: 2020-08-15 19:41:04
*/
#include <iostream>
#include <algorithm>
using namespace std;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0; // a * 1 + b * 0 = a 递归边界
        return a; //最大公约数
    }
    int d = exgcd(b, a % b, y, x);
    y -=(a/b) * x;
    return d;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    int a, b, x, y;
    
    while(n--){
        cin >> a >> b;
        int d = exgcd(a, b, x, y);
        cout << x <<' ' << y << endl;
    }
    
    return 0;
}