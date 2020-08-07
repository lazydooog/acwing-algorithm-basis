/*
* @Description: 831. kmp字符串
* @Author: Xiaobin Ren
* @Date:   2020-04-05 18:52:47
* @Last Modified time: 2020-08-07 23:21:55
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

//2020.8.7重写板子

/*
给定一个模式串S，以及一个模板串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模板串P在模式串S中多次作为子串出现。

求出模板串P在模式串S中所有出现的位置的起始下标。

输入格式
第一行输入整数N，表示字符串P的长度。

第二行输入字符串P。

第三行输入整数M，表示字符串S的长度。

第四行输入字符串S。

输出格式
共一行，输出所有出现位置的起始下标（下标从0开始计数），整数之间用空格隔开。

数据范围
1≤N≤105
1≤M≤106
*/

#include <iostream>
using namespace std;

const int N = 100010, M = 1000010;
int n, m;
char p[N], s[M];
int ne[N];  // Next 数组是对短串而言的


int main(){
    cin >> n >> p + 1 >> m >> s + 1;  // kmp 这个板子长短串都从下标为1开始匹配
    
    //求next数组 ne[1] = 0;  求next的思路和kmp的思路一样 不过相当于自己匹配自己的循环节 用双指针
    for(int i = 2, j = 0; i <=n; i++){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    
    
    
    for(int i = 1, j = 0;i <= m; i++){  // i是长串的指针 j是短串的指针
        while(j && s[i] != p[j+1]) j = ne[j]; //第一个判断是j到头了 那就下边代码不执行 直接下一轮循环 i后移一位开始匹配
        if (s[i] == p[j+1]) j++; //循环节的下一位匹配上了 继续往后匹配
        if(j == n){
            //匹配成功
            
            cout << i - n << ' ';   //输出起始位置 其实是减去1的结果 板子的下标是从1开始的
            j = ne[j]; //继续用当前匹配上的循环节的起始节处开始匹配
        }
    }
    
    return 0;
}


