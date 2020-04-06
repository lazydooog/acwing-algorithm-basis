/*
* @Description: 838. 堆排序
* @Author: Xiaobin Ren
* @Date:   2020-04-06 17:02:22
* @Last Modified time: 2020-04-06 17:22:33
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n ,m;
int h[N], size;

void down(int u){  //下沉操作
	int t = u;
	if(u*2 <= size && h[u*2] < h[t]) t = u*2;   // u*2 <= size 判断节点是否存在
	if(u*2+1 <= size && h[u*2+1] < h[t]) t = u*2+1;
	if(u != t) {  //没有进入if循环，说明到底了
		swap(h[u], h[t]);
		down(t);   //递归
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
	size = n;

	for(int i = n/2; i; i--) down(i);  
	//建堆技巧，复杂度 O(n), 从倒数第二层向上，逐层来down . n / 2 是倒数第二层最后一个节点

	while(m--){
		printf("%d ", h[1]);
		h[1] = h[size];
		down(1);
	}

	return 0;
}