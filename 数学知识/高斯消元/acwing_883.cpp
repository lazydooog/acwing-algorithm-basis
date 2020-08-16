/*
* @Description: 883. 高斯消元解线性方程组
* @Author: Xiaobin Ren
* @Date:   2020-08-16 15:32:01
* @Last Modified time: 2020-08-16 16:09:17
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 110;
const double eps = 1e-6;
double a[N][N];
int n;

void out(){ //debug
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            printf("%.2f\t", a[i][j]);
        }
        puts("");
    }
}

int gauss(){
    int c, r;  //列和行
    for(c = 0, r = 0; c <n; c++){//列向右移动 因为要变成上三角矩阵 注意：该矩阵是 n * (n + 1) 的
        int t = r;
        for(int i = r; i < n; i++)  //求出绝对值最大的行
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        if(fabs(a[t][c]) < eps) continue;  //绝对值最大也是0 说明这一列全0 直接下一列c++即可
        
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]);  //把这一行换到最上面(第r行) 也就是是固定行的下一行
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c]; //第一个数变成1 后边的同时改变
        for(int i = r + 1; i < n; i++)//把第一个数下面该列的元素 都消成0 行下标是 0 ~ n-1 
            if(fabs(a[i][c]) > eps) // 这一行该列元素不是0 才需消掉
                for(int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c]; //被消去的元素减去 第r行元素 * 该行第一个元素，因为r行第一个是1
        r ++;       
    }
    
    if(r < n){ //不是有唯一解
        for(int i = r; i < n; i++)
            if(fabs(a[i][n]) > eps)  //0  == 非0 
                return 2;  //无解
        return 1;//无穷多解
    }
    //有唯一解 将增广矩阵化为简化阶梯矩阵 每行最后一个元素就是唯一解了
    //这里就是把每行 元素 1 后边的非0元素全部改为0  每行的1将该1所在列上方元素全部消成0
    //但是事实上并没有消 只对于每行的最后一个元素在模拟这个过程 输出最后的矩阵 不是简化阶梯矩阵
     for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];
            
    return 0;  // 唯一解
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n+1; j++) //每行n + 1 个元素
            cin >> a[i][j];
            
    int t = gauss();
    if(t == 0){
        //out(); //debug
        for(int i = 0; i < n; i++) printf("%.2f\n", a[i][n]);  //最后矩阵系数都是1 最后列常数列就是解
    }else if(t == 1) puts("Infinite group solutions");  //无数解
    else puts("No solution");  //无解
    
    return 0;
}