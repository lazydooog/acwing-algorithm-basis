/*
* @Description: 890. 能被整除的数
* @Author: Xiaobin Ren
* @Date:   2020-08-17 22:04:05
* @Last Modified time: 2020-08-17 22:04:12
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
//用集合S[i] 表示 1到n中能被i整除的数的集合 集合大小为 n / i
//然后 一共有m个集合 处理一个集合需要m次 最后复杂度O(2 ^ m * m)
//容斥原理 + 二进制状压

const int N = 20;

int n, m;
int p[N];

//主要思维：对于交集的意义，p1 ∩ p2 ∩ .... 意思是任意一个p都能整除 那么集合大小就是 n/(p1*p2....) 

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> p[i];
    
    int res = 0;
    
    for(int i = 1; i < 1 << m; i++){//枚举容斥原理表达式 的2^n - 1 项 
        int t = 1, cnt = 0;  //cnt表示当前i包含几个1 也就是当前选法有几个集合  t代表当前的乘积
        for(int j = 0; j < m; j++)
            if(i >> j & 1){
                cnt ++;
                if(1ll * t * p[j] > n){ //能同时被p1 p2 p3....整除的 个数为n / (p1* p2 * ....pi) 如果大于n就不能整除
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        if(t != -1){
            if (cnt & 1) res += n / t; //由容斥原理 如果有奇数个集合 就加上 偶数就减去
            else res -= n / t;
        }
    }
    
    cout << res << endl;
    
    return 0;
}
