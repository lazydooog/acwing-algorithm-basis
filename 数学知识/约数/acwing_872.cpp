/*
* @Description: 872. 最大公约数
* @Author: Xiaobin Ren
* @Date:   2020-08-14 22:57:57
* @Last Modified time: 2020-08-14 22:58:03
*/
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b){ //比库函数慢
    return b ? gcd(b, a % b) : a;
}

int main(){ //直接用algorithm 库函数即可 做法一
    int n;
    cin >> n;
    int a, b;
    while(n --){
        cin >> a >> b;
        //cout << __gcd(a, b) << endl;
    
        cout << gcd(a, b) << endl;
    }
    
    return 0;
}