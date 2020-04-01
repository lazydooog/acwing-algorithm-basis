/*
 * @Description: 786. 第k个数
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 20:59:00
 * @LastEditTime: 2020-04-01 21:50:33
 */

//排序直接输出，注意下标  复杂度 O(N*logN)

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n,&k);
    int a[100010];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    cout<< a[k-1] << endl;
    return 0;
}

//快速选择算法 复杂度 O(n) 基于快排改进
//每次划分之后只需要处理一边即可，快排需要同时处理两边

#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int quick_sort(int l, int r, int k){
    if(l == r) return a[l];
    int x = a[l], i = l-1, j = r+1;  // x是划分标记
    while(i<j){
        while(a[++i] < x); while(a[--j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    int sl = j-l+1;  //sl是划分标记左边的元素个数,下标为k的数字是第k+1大的
    if(k <= sl) return quick_sort(l, j, k);
    return quick_sort(j+1, r, k-sl);
}

int main(){
    int n, k;
    
    scanf("%d%d", &n,&k);
    for(int i = 0; i< n;i++) scanf("%d",&a[i]);
    cout << quick_sort(0, n-1, k) << endl;
    
    return 0;
}