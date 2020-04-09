/*
* @Description: 843. n皇后问题
* @Author: Xiaobin Ren
* @Date:   2020-04-09 10:51:23
* @Last Modified time: 2020-04-09 11:05:10
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
		//这里处理对角线的思路是用y轴的截距来判整个对角线
		//因为同一个对角线的截距都相同
		// n - u + i 由于左对角线截距可能为负值，但是数组下标不能为负，加上n全部偏移，结果不影响
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
