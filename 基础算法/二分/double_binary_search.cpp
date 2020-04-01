/*
 * @Description: 浮点数二分模板
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 20:07:46
 * @LastEditTime: 2020-04-01 20:08:03
 */

bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}