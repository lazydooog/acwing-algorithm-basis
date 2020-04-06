/*
* @Description: 836. 合并集合
* @Author: Xiaobin Ren
* @Date:   2020-04-06 10:34:53
* @Last Modified time: 2020-04-06 10:52:19
*/

#include <iostream>
using namespace std;

const int N = 100010;
int p[N];  //父节点
int n, m;

int find(int x){  //返回x的祖宗节点 并且 路径压缩

	if(p[x] != x) p[x] = find(p[x]);  //递归出栈会将路径所有节点的父节点改为祖宗节点
	return p[x];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) p[i] = i;
	while(m --){
		char op[2];
		int a, b;
		scanf("%s%d%d", op, &a, &b);

		if(op[0] == 'M') p[find(a)] = find(b);
		else{
			if (find(a) == find(b)) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}