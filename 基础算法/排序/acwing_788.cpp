/*
 * @Description: 788. 逆序对的数量
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 20:59:11
 * @LastEditTime: 2020-04-02 09:39:18
 */

/*
    归并排序的板子 加一行代码就可以了 29行
    分治的思想：先求左边逆序对的数量 再求右边
    最后加上一左一右的情况的个数

    一左一右的处理：此时已经左边有序，右边有序。当左边第 i 个元素大于右边第 j 个元素
    那么左边 i 后边的所有元素都比 j 大，直接加上即可。这样就对于右边为参考
    处理了所有和 j 互为逆序对的情况。
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100010;
int tmp[N]; ll res = 0;
int a[N];

ll merge_sort(int l, int r){
    if(l >= r) return 0;
    int mid = l + ((r-l) >> 1);
    res = merge_sort(l, mid)+ merge_sort(mid+1, r);
    int k = 0, i = l, j = mid+1;
    while(i<=mid && j<=r){
       if(a[i] <= a[j]) tmp[k++] = a[i++];
       else{
           tmp[k++] = a[j++];
           res += mid - i +1;   //加上第三种情况
       }
    }
    //扫尾
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    
    for(int i = l, j = 0; i<=r; i++, j++) a[i] = tmp[j];
    return res;
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    cout << merge_sort(0, n-1) << endl;
    
    return 0;
}







