/*
* @Description: 843. n皇后问题
* @Author: Xiaobin Ren
* @Date:   2020-04-09 10:51:23
* @Last Modified time: 2020-04-09 10:57:31
*/

#include <iostream>

using namespace std;

const int N = 20;

int n; char g[N][N];
bool col[N], dg[N], udg[N]; //列 左对角线 右对角线

void dfs(int u){
	if(u == n){
		for(int i = 0; i < n; i++) puts (g[i]);
			puts("");
		return;
	}

	for(int i  = 0; i < n; i++)
		if(!col[i] && !dg[u+i] && !udg[n - u + i]){
			g[u][i] = 'Q';
			col[i] = dg[u+i] = udg[n-u+i] = true;
			dfs(u + 1);
			col[i] = dg[u+i] = udg[n-u+i] = false;  //恢复现场
			g[u][i] = '.';
		}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0);

	return 0;
}
