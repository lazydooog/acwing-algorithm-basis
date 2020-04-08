/*
* @Description: 841. 字符串哈希
* @Author: Xiaobin Ren
* @Date:   2020-04-08 11:54:05
* @Last Modified time: 2020-04-08 12:32:44
*/

#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010;
const int  P= 131;

int n,m;
char str[N];
ULL h[N], p[N];  //p[]存储p的次方,h[] 存储哈希值

ULL get(int l, int r){
	return h[r] - h[l - 1] * p[r - l + 1];
} 

int main(){
	scanf("%d%d%s", &n, &m, str+1);  //从下标1开始
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] * P;
		h[i] = h[i-1] * P + str[i];  //哈希函数
	}
	while(m--){
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(get(l1, r1) == get(l2,r2)) puts("Yes");
		else puts("No");
	}
	return 0;
}