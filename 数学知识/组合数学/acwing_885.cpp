/*
* @Description: 885. 求组合数 I (递推)
* @Author: Xiaobin Ren
* @Date:   2020-08-16 17:14:03
* @Last Modified time: 2020-08-16 17:14:34
*/
#include <iostream>
#include <algorithm>
using namespace std;

//递推复杂度 O(n^2)


const int N = 2010, mod = 1e9 +7;
int n;
int c[N][N];

void init(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
}

int main(){
    cin >> n;
    int a, b;
    init();
    while(n --){
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
        
    return 0;
}