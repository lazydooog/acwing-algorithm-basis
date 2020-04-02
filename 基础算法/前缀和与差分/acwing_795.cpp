/*
 * @Description: 795. 前缀和
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:01:15
 * @LastEditTime: 2020-04-02 17:38:57
 */

#include <iostream>
using namespace std;

int n,m; const int N = 100010;
int a[N], s[N];

int main(){
    scanf("%d%d", &n ,&m);
    for(int i = 1; i <= n; i++) scanf("%d" ,&a[i]); //注意前缀和下标都是从1开始
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    
    while(m--){
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l-1]);
    }
}