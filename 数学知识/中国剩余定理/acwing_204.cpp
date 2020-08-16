/*
* @Description: 204. 表达整数的奇怪方式
* @Author: Xiaobin Ren
* @Date:   2020-08-16 11:44:54
* @Last Modified time: 2020-08-16 11:45:04
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll; //答案用64位整数存储

// mi < ai 那么mi模ai的余数就是mi 则转换为 x模ai的余数就是mi
//此题ai之间没有满足互质关系 所以只能归纳 用扩展欧几里得计算
//最后的同解为 x = x0 + k * a  ,  x0是一个特解 这个a最后就是所有ai的最小公倍数 可以带进去验证

ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y ,x);
    y -= (a/b) * x;
    
    return d;
}

int main(){
    int n; cin >> n;
    ll a1, m1;  //现有方程 然后用后面的向里面归纳合并
    bool flag = 1;
    cin >> a1 >> m1;
    for(int i  =0; i < n - 1; i++){  //后边的n - 1 个方程
        ll a2, m2;
        cin >> a2 >> m2;
        ll k1, k2;
        ll d = exgcd(a1, a2, k1, k2);  
        if((m2 - m1) % d){  //无解
            flag = 0;
            break;
        }
        k1 *= (m2 - m1) / d; // 翻倍求特解，exgcd求出了gcd
        ll t = a2 / d; //通解后边 K倍的系数 即 x = x0 + k(a2/d); 这里其实d是1?
        k1 = (k1 % t + t) % t;  //最小的解 对ai/gcd(ai, 1)取模
        
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);  //最小公倍数 更新a
    }
    
    if(flag)
        cout << (m1 % a1 + a1) % a1 << endl;
    else cout << -1 << endl;
    return 0;
}