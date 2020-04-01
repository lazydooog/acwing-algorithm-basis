/*
 * @Description: Acwing 789. 数的范围
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 18:20:20
 * @LastEditTime: 2020-04-01 19:50:32
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


//手写二分
#include <iostream>
using namespace std;
const int N = 100010;
int n, m, q[N];


int main(){
    scanf("%d%d", &n,&m);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    while(m--){
        int x;
        scanf("%d", &x);
        
        //查找存在，若存在求出下界
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= x) r= mid;
            else l = mid+1;
        }
        if(q[l]!=x) cout << "-1 -1" << endl;
        
        //求出上界
        else{
            cout << l << " ";  //先输出已经存在的上界
            
            //求上界
            int l = 0, r = n-1;
            while(l < r){
                int mid = l+r+1 >> 1;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}


