/*
* @Description: 291. 蒙德里安的梦想
* @Author: Xiaobin Ren
* @Date:   2020-08-23 16:19:04
* @Last Modified time: 2020-08-23 16:19:11
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 12, M = 1 << N;
int n, m;
ll f[N][M]; //f[i][j]  表示 第i列的形态为j时 前i列的分割方案总数
bool st[M];  

int main(){

    while(cin >> n >> m , n || m){
        memset(f, 0 ,sizeof f);
        for(int i = 0; i < 1 << n; i++){
            st[i] = true;
            int cnt = 0;  //当前这一段 连续0的个数
            for(int j = 0; j < n; j++)
                if(i >> j & 1){  //到1就结束这一段
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }else cnt ++;
                
            if(cnt & 1) st[i] = false;
        }
        f[0][0] = 1; //第0列 全0状态 只能竖着放 所以只有一种方案
        for(int i = 1; i <= m; i++) //枚举列从左到右
            for(int j = 0; j < 1 << n; j++)  //行的状态
                for(int k = 0; k < 1 << n; k++) //第i - 1 列的状态
                    if((j & k) == 0 && st[j | k])
                        f[i][j] += f[i - 1][k];
        
        cout << f[m][0] << endl;  //第m列  全0 状态
    }
    return 0;
}