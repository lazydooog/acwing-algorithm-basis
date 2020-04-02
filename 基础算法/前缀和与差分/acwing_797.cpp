/*
 * @Description: 797. 差分
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:01:32
 * @LastEditTime: 2020-04-02 21:35:06
 */

/*
    给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
    A是B数组的前缀和，那么B就是A数组的差分
    给某个区间都加上 c ，就要先逆推出差分数组，再操作差分数组
    最后对差分数组求前缀和，得到的新数组就是要求变化后的A的数组
*/

#include <iostream>
using namespace std;
const int N = 100010;
int a[N],b[N];
int n ,m; 

void insert(int l, int r, int c){
    b[l] += c;
    b[r+1] -= c;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
   // for(int i = 1; i <= n; i++) insert(i, i, a[i]);  //这种构造差分比较抽象，下边的好理解
    for(int i = 1; i <= n; i++) b[i] = a[i] - a[i-1];
    while(m--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for(int i = 1; i<=n; i++) b[i] += b[i-1];
    for(int i = 1; i <= n; i++) printf("%d ", b[i]);
}

