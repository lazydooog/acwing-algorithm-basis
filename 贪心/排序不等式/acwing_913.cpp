/*
* @Description: 913. 排队打水
* @Author: Xiaobin Ren
* @Date:   2020-08-26 14:59:14
* @Last Modified time: 2020-08-26 14:59:21
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N], s[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a+1, a + 1 +n);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    long long  res = 0;
    for(int i = 1; i <= n; i++) res += s[i-1];
    
    cout << res << endl;
    
    return 0;
}