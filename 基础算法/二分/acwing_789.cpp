/*
 * @Description: Acwing 789. 数的范围
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 18:20:20
 * @LastEditTime: 2020-04-01 18:24:29
 */


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

//做法1
int main(){
    int n, q, kase;
    int a[N];
    scanf("%d%d", &n,&q);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    while(q--){
        scanf("%d", &kase);
        if(binary_search(a, a+n, kase)){
            int pos1 = lower_bound(a, a+n, kase) - a;
            int pos2 = upper_bound(a, a+n, kase) - a - 1;
            printf("%d %d\n", pos1, pos2);
        }
        else printf("%d %d\n", -1, -1);
    }
    
    return 0;
}


