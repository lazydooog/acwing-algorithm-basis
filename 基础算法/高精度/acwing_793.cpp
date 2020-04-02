/*
 * @Description: 793. 高精度乘法
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:00:35
 * @LastEditTime: 2020-04-02 16:01:05
 */

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;

VI mul(VI &a, int b){
    int t = 0;
    VI c;  //答案
    for(int i = 0; i < a.size() || t; i++){
       if(i < a.size()) t += a[i] * b;
       c.push_back(t%10); t /= 10;
    }
    return c;
}

int main(){
    string a;
    int b;
    cin >> a >> b;
    VI A;
    for(int i = a.size()-1; i >=0; i--) A.push_back(a[i] - '0');
    auto c = mul(A, b);
    for(int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
   
   return 0;
}