/*
 * @Description: 790. 数的三次方根
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 20:31:45
 * @LastEditTime: 2020-04-01 20:34:17
 */


/*
    浮点数二分，
    注意对于开根问题的边界范围：
    浮点数开根号之后可能比自己要小，而且有可能是负数
    最好的方法就是直接枚举题目给出的数据范围
    以此来作为左右边界
*/
#include <iostream>

using namespace std;

int main(){
    double x; scanf("%lf", &x);
    double l = -10000 , r = 10000;
    const double eps = 1e-8;   //这里的8 是 6+2， 一般比题目所求的小数点精度大 2
    while(r - l > eps){
        double mid = (r+l) /2 ;
        if(mid*mid*mid >= x) r = mid;
        else l = mid;
    }
    printf("%.6f", l);
    
}