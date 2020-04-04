/*
* @Description: 双链表模板
* @Author: Xiaobin Ren
* @Date:   2020-04-04 18:45:55
* @Last Modified time: 2020-04-04 19:51:26
*/

// e[]表示节点的值，l[]表示节点的左指针，r[]表示节点的右指针，idx表示当前用到了哪个节点
//链式前向星就是数组模拟的链表 一个东西

int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    //0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 在节点k的右边插入一个数x
//在节点k的左边插入一个数很简单，直接使用insert(l[k], x)即可,相当于在这个数的左边一个数的右边插入
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx ++ ;
}

// 删除节点k
void remove(int k)
{
    l[r[k]] = l[k];  //这两句是没有先后关系的
    r[l[k]] = r[k];
}