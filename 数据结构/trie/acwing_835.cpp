/*
* @Description: 835 Trie 字符串统计
* @Author: Xiaobin Ren
* @Date:   2020-04-06 09:37:28
* @Last Modified time: 2020-04-06 10:02:39
*/

#include <iostream>
using namespace std;

const int N = 100010;

int son[N][26];  //所有节点的子节点
int cnt[N]; //以当前节点节点为结尾的字符串的个数
int idx;  // 下标是 0 的点 ，既是根节点，又是空节点

char str[N];

//插入
void insert(char *str){

	int p = 0;  //根节点
	for(int i = 0; str[i]; i++){  //字符串以 '\0' 来结束，可以以此来判断
		int u  = str[i] - 'a';  //转化成数字来存储
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p] ++;
}
//查询次数
int query(char *str){
	int p = 0;
	for(int i = 0; str[i]; i++){
		int u = str[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main(){
	int n; scanf("%d", &n);
	while(n--){
		char op[2];
		scanf("%s%s", op, str);
		if(op[0] == 'I') insert(str);
		else printf("%d\n", query(str));
	}
	return 0;
}
