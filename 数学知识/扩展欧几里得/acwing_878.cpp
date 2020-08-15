/*
* @Description: 878. 线性同余方程
* @Author: Xiaobin Ren
* @Date:   2020-08-15 22:59:13
* @Last Modified time: 2020-08-15 22:59:22
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
int n;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y  = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    
    return d;
}

int main(){
    cin >> n;
    int a, b ,m;
    int x, y;
    while(n --){
        cin >> a >> b >> m;
        
        int d = exgcd(a, m, x, y);
        
        if(b % d) puts("impossible");
        else cout << (ll)x * (b / d) % (m / d) << endl; //  乘的结果可能爆int 所以用long long 存储之后再取模
        //如果直接用int存再取模 答案错误 因为int会溢出 注意模数 m / gcd(a, m) 都是和特解x 同余的 也可以直接模m
    }
    
    return 0;
}