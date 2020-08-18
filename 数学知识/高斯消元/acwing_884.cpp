/*
* @Description: 884. 高斯消元解异或线性方程组
* @Author: Xiaobin Ren
* @Date:   2020-08-18 22:49:20
* @Last Modified time: 2020-08-18 22:49:28
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N  = 110;
int a[N][N];
int n;


int gauss(){
    int r, c;
    for(r=c=0; c < n; c++){  //外层枚举列
        int t = r;
        for(int i = r; i < n; i++)
            if(a[i][c]){
                t = i;
                break;  //找到一个非0行即可
            }
        if (!a[t][c]) continue;  //该列全部都是0 直接下一列
        
        //该行交换上去 最上面 未固定的
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]); //从左往右扫 交换2行的每一个元素
        
        for(int i = r + 1; i < n; i++)  //将1下边的全部消成0
            if(a[i][c])
                for(int j = c; j <= n; j++)
                    a[i][j] ^= a[r][j];   //  下边如果是0 那异或1还是0  如果是1  那和1异或之后就是0了
        r++;
    }
    
    if(r < n) {
        for(int i = r; i < n; i++) //此时的r所在的行 就是只有一个未知数的方程 开始判断0 = 非0
            if(a[i][n]) return 2;  //无解
        return 1;  //无数解
    }
    
    //用每一行的主元 消去该列的上边的数 全部为0
    
    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            a[i][n] ^= a[i][j] & a[j][n];
            
    return 0;  //唯一解
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0 ; j < n + 1; j++)
            cin >> a[i][j];
            
    int res = gauss();
    
    
    if(res == 0){  //唯一解
        for(int i = 0; i < n; i++) cout << a[i][n] << endl;
    }else if(res == 1){ //无数解
        cout << "Multiple sets of solutions" << endl;
    }else cout << "No solution" << endl;
    
    return 0;
}