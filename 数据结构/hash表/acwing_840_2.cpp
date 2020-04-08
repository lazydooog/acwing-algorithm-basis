/*
* @Description: 840. 模拟散列表
* @Author: Xiaobin Ren
* @Date:   2020-04-08 10:44:13
* @Last Modified time: 2020-04-08 10:51:18
*/

//开放寻址法

#include <iostream>
#include <cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
	int k = (x % N + N) % N;

	while(h[k] != null && h[k] != x)
	{
		k ++;
		if (k == N) k = 0;
	}
	return k;   //如果没找到就是返回一个新的null位置
}

int main()
{
	int n;
	scanf("%d", &n);
	memset(h, 0x3f, sizeof h);

	while(n--)
	{
		char op[2];
		int x;
		scanf("%s%d", op, &x);

		int k = find(x);
		if (op[0] == 'I') h[k] = x;
		else
		{
			if (h[k] != null) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}