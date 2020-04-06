/*
* @Description: 840. 模拟散列表
* @Author: Xiaobin Ren
* @Date:   2020-04-06 22:36:02
* @Last Modified time: 2020-04-06 22:44:41
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;

void insert(int x){
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];  //插到链表头，表头就是h[k]
	h[k] = idx++;
}

bool find(int x){
	int k = (x % N + N) % N;
	for(int i = h[k]; i != -1; i = ne[i]){
		if (e[i] == x) return true;
	}
	return false;	
}

int main(){
	int n;
	scanf("%d", &n);
	memset(h ,-1, sizeof h);

	while(n --){
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'I') insert(x);
		else{
			if(find(x)) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}
