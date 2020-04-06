/*
* @Description: 831. kmp字符串
* @Author: Xiaobin Ren
* @Date:   2020-04-05 18:52:47
* @Last Modified time: 2020-04-06 09:18:08
*/

/*
// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
//求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}
*/
#include <iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
char p[N], s[M];
int ne[N];

int main(){
	cin >> n >> p+1 >> m >> s+1;

	//求next 数组  //n是短串的长度 m是长串 的长度 这里和板子的长度是反的注意
	for(int i = 2, j = 0; i <= n; i++){
		//next[1] = 0; 因为第一个的前缀就是自己本身
		while(j && p[i] != p[j+1]) j = ne[j];
		if(p[i] == p[j+1]) j++;
		ne[i] = j;
	}

	//匹配
	for(int i = 1, j = 0; i <= m; i++){
		while(j && s[i] != p[j+1]) j = ne[j];
		if (s[i] == p[j+1]) j++;
		if(j == n){
			// 匹配成功
			printf("%d ", i - n);  //下标从一开始，但是题目从0开始所以是i - n
			j = ne[j]; //寻找下一个匹配成功的位置
		}
	}
}