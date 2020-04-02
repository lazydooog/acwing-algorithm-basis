/*
 * @Description: 794. 高精度除法
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:00:43
 * @LastEditTime: 2020-04-02 17:07:43
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

VI div(VI &a, int b, int &r){
    r = 0; 
    VI c;  //答案
    for(int i = a.size()-1; i >= 0; i--){
        r = r*10 + a[i];
        c.push_back(r/b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back()==0) c.pop_back();
    
    return c;
}

int main(){
    string a; int b;
    cin >> a >> b;
    int r = 0; VI A;
    for(int i  = a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');
    auto c = div(A, b, r);
    for(int i = c.size()-1; i>=0;i--) printf("%d", c[i]);
    printf("\n");
    printf("%d\n", r);
}




