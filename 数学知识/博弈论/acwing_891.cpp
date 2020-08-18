/*
* @Description: 891. Nim游戏
* @Author: Xiaobin Ren
* @Date:   2020-08-18 17:20:20
* @Last Modified time: 2020-08-18 17:20:26
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int main(){
    cin >> n;
    int x;
    
    ll res = 0;
    
    while(n--){
        cin >> x;
        res ^= x;
    }
    if(res == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}