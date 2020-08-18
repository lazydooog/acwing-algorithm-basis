/*
* @Description: 893. 集合-Nim游戏
* @Author: Xiaobin Ren
* @Date:   2020-08-18 22:16:21
* @Last Modified time: 2020-08-18 22:16:31
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;
const int N = 110, M = 10010;

//每一堆石子都可以看为一个有向图，然后求初始节点的SG函数 每一个节点的出边对应能取的所有状态

int n, m;
int s[N], f[M];  //s表示集合的元素 ，f 是sg函数值


int sg(int x){
    if(f[x] != -1) return f[x];  //记忆化 被算过就直接返回 
    unordered_set<int> S; //储存所有可以到达的局面
    for(int i = 0; i <m; i++){
        int sum = s[i];
        if(x >= sum) S.insert(sg(x - sum)); 
    }
    
    for(int i = 0; ; i++) // 求当前节点的mex函数值 最小的不包含的非负整数
        if(!S.count(i))
            return f[x] = i;
}

int main(){
    cin >> m;
    for(int i = 0; i < m; i++) cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof f);
    
    int res = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        res ^= sg(x);  //求出每一个有向图的sg函数 然后全部异或
    }
    
    if(res == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
    
    
}