/*
 * @Description: 整数二分算法模板
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 11:07:13
 * @LastEditTime: 2020-04-01 20:06:25
 */

/*
    对于两个模板，具体使用哪一个
    直接看判断的条件为真时候，是在左半区间还是在右半区间
    左半就是 l = mid  右半就是 r = mid

    解题时候先确定当前情况所在的区间 然后再确定用哪一个模板
*/

bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
