/*
* @Description: 861. 二分图的最大匹配
* @Author: Xiaobin Ren
* @Date:   2020-08-14 11:09:27
* @Last Modified time: 2020-08-14 11:09:35
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;
int n1, n2, m;
int h[N], ne[M], e[M], idx;
int match[N];  //右边的点 对应左边的匹配点是哪个
bool v[N];

//枚举左边的点 边的存储方向为左指向右边 
//由于是二分图 所以左边部分点之间不可能有边，直接左右节点编号一样 混用无所谓 直接存就好
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool dfs(int x){ //只对左边的一个点进行的dfs操作
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!v[j]){  // 该右边的点还没有被左边该点匹配过
            v[j] = true;
            if(!match[j] || dfs(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    memset(h ,-1 ,sizeof h);
    cin >> n1 >> n2 >> m;
    int a, b;
    while(m --){
        cin >> a >> b;
        add(a, b);
    }
    
    int res = 0;  //最终答案 最大匹配边数
    
    for(int i = 1; i <= n1; i++){ //枚举左边所有点
        memset(v, 0 ,sizeof v); //每次枚举都清空右边的点 进行匹配
        if(dfs(i)) res++;
    }
    
    cout << res << endl;
    
    return 0;
}


