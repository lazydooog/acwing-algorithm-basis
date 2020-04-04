/*
 * @Description: 单链表
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 11:27:24
 * @LastEditTime: 2020-04-01 11:27:42
 */

/*
	用结构体 + 指针实现的链表每次加一个节点都要new一次，分配内存
	非常慢 所以要用数组来模拟，但是数组模拟的是静态链表
*/

// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

//初始化
void init(){
	head = -1;
	idx = 0;
}
//将 x 插到头节点
void add_to_head(int x){
	e[idx] = x, ne[idx] = head, head = idx++;
}

//将 x 插到下标是 k 的点后边
void add(int k, int x){
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}

//将下标是 k 后边的节点删除
void remove(int k){
	ne[k] = ne[ne[k]];
}
