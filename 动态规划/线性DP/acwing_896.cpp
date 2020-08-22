/*
* @Description: 896. 最长上升子序列 II
* @Author: Xiaobin Ren
* @Date:   2020-08-22 11:33:04
* @Last Modified time: 2020-08-22 11:33:39
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];
int q[N];  //储存上升子序列 结尾的最小值 

//二分优化 复杂度 n * log n

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int len = 0;  //q元素个数
    
    q[0] = -2e9;  //边界
    
    for(int i = 0 ; i < n; i++){
        int l = 0, r = len;
        while(l < r){
            int mid = l + r + 1>> 1;
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    
    cout << len << endl;
    
    return 0;
}