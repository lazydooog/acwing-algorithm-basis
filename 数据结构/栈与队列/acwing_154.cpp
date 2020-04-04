/*
* @Description: 154 滑动窗口
* @Author: Xiaobin Ren
* @Date:   2020-04-04 23:35:56
* @Last Modified time: 2020-04-05 00:16:48
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, k;
int a[N], q[N];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	int hh = 0, tt = -1; // hh是队头 tt是队尾
	for(int i = 0; i < n; i++){
		if(hh <= tt && i -k +1 >q[hh]) hh++;
		while(hh <= tt && a[q[tt]] >= a[i]) tt--;
		q[++tt] = i;

		if(i >= k-1) printf("%d ", a[q[hh]]);
	}
	puts("");

	hh = 0, tt = -1; // hh是队头 tt是队尾
	for(int i = 0; i < n; i++){
		if(hh <= tt && q[hh] < i - k + 1) hh++;
		while(hh <= tt && a[q[tt]] <= a[i]) tt--;
		q[++tt] = i;

		if(i >= k-1) printf("%d ", a[q[hh]]);
	}
	puts("");

	return 0;
}