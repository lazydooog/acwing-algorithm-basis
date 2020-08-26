/*
* @Description: 104. 货仓选址
* @Author: Xiaobin Ren
* @Date:   2020-08-26 15:01:40
* @Last Modified time: 2020-08-26 15:01:50
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int pos, sum = 0;
    pos =  a[n / 2 + 1];
    
    for(int i = 1; i <= n; i++) sum += abs(a[i] - pos); 
    
    printf("%d", sum);
    
    return 0;
}