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
//idx 其实就是内存池指针 没有实际意义，idx每次都会一直加一，
//意思是即使在中间插入一个元素，e[]中的该元素的值却一直在最后末尾加上
//所以在 e[] 中的值的排列
//并不是按照链表的先后节点顺序来排列的，在e[]中索引的时候是跳过去跳过来索引
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
