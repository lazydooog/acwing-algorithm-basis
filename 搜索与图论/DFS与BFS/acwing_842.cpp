/*
* @Description: 842. 排列数字
* @Author: Xiaobin Ren
* @Date:   2020-04-08 19:23:31
* @Last Modified time: 2020-04-08 19:28:14
*/
#include <iostream>

using namespace std;

const int N = 10;

int n, path[N];  // path记录当前的枚举状态
bool st[N];  //标记是否被用过

void dfs(int u){
	if(u == n){
		for(int i = 0; i < n; i++) printf("%d ", path[i]);
			puts("");
			return ;
	}

	for(int i = 1; i <= n; i++){
		if(!st[i]){
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			st[i] = false;  //恢复现场
		}
	}
}

int main(){
	scanf("%d", &n);
	dfs(0);

	return 0;
}
