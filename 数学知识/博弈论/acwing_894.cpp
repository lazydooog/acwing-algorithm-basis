/*
* @Description: 894. 拆分-Nim游戏
* @Author: Xiaobin Ren
* @Date:   2020-08-19 11:08:15
* @Last Modified time: 2020-08-19 11:08:23
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;


//石子堆的最大值在减小 所以博弈一定会结束
//每堆石子看坐有向图 然后全部求SG函数 

const int N = 110;
int f[N];

int sg(int x){
    if(f[x] != -1) return f[x];
    
    unordered_set<int> S;
    
    //枚举可以到达的状态
    for(int i = 0; i < x; i++)//第一堆
        for(int j = 0; j <= i; j++) //第二堆
            S.insert(sg(i) ^ sg(j));
            
    //mex 函数
    for(int i = 0; ; i++)
        if(!S.count(i)) 
            return f[x] = i;
        
}

int main(){
    int n;
    cin >> n;
    int res = 0;
    memset(f, -1, sizeof f);
    
    while(n --){
        int x; 
        cin >> x;
        res ^= sg(x);
    }
    
    if(res == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}