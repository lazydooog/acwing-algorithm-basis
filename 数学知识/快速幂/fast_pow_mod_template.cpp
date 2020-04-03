/*
* @Description: 快速幂模板
* @Author: Xiaobin Ren
* @Date:   2020-04-03 21:21:21
* @Last Modified time: 2020-04-03 21:21:35
*/

//求 m^k mod p，时间复杂度 O(logk)。

int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}