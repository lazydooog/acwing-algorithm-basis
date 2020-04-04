/*
* @Description: 单调栈模板
* @Author: Xiaobin Ren
* @Date:   2020-04-04 20:20:23
* @Last Modified time: 2020-04-04 20:20:39
*/

//常见模型：找出每个数左边离它最近的比它大/小的数
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}

