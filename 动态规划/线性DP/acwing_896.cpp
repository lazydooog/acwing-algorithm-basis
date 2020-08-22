/*
* @Description: 896. 最长上升子序列 II
* @Author: Xiaobin Ren
* @Date:   2020-08-22 11:33:04
* @Last Modified time: 2020-08-22 12:15:02
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];
int q[N];  //储存上升子序列 每种长度下 结尾的最小值 

//其实本质是向右同时维护很多个子序列，然后取长度最长的一个

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
        q[r + 1] = a[i]; //新的a[i] 接到前面所有已经求的子序列 比a[i] 小的 结尾最大的数后边 保持最优性  q[]只保存结尾元素
    }
    
    cout << len << endl;
    
    return 0;
}