/*
* @Description: 869. 试除法求约数
* @Author: Xiaobin Ren
* @Date:   2020-08-14 20:26:08
* @Last Modified time: 2020-08-14 20:26:15
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5;
int factor[N];  //储存所有约数

int n;
//试除法 复杂度 O(sqrt(N)) 
void divide(int n){
    int m = 0;
    for (int i = 1; i <= n / i; i++){
        if(n % i == 0){
            factor[m++] = i;
            if(i != n / i) factor[m++] = n / i;   //这一个特判是防止 平方数 的约数重复加入
        } 
    }
    sort(factor, factor + m); //从小到大输出
    for(int i = 0; i < m; i ++) cout << factor[i] << ' ';
    cout << endl;
}

int main(){
    cin >> n;
    int x;
    while(n --){
        cin >> x;
        divide(x);
    }
    
    return 0;
}