/*
 * @Description: 高精度除以低精度 模板
 * @Author: Xiaobin Ren
 * @Date: 2020-04-02 16:42:58
 * @LastEditTime: 2020-04-02 17:07:22
 */

// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    //为了统一加减乘除，因为一道题可能同时用到加减乘除
    //除法本来顺着存更加简单，但是为了统一逆序存储
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());  //反转整个数组
    while (C.size() > 1 && C.back() == 0) C.pop_back();
     //逐位模拟，会存在前导零，要去除前导零
    return C;  //返回的答案也是逆序存储的
}