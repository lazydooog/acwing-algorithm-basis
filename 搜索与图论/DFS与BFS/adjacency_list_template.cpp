/*
* @Description: 邻接表模板
* @Author: Xiaobin Ren
* @Date:   2020-04-03 21:18:54
* @Last Modified time: 2020-04-03 21:19:10
*/

// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// 初始化
idx = 0;
memset(h, -1, sizeof h);