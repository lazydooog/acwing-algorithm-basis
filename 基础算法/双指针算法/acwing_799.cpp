/*
 * @Description: 799. 最长连续不重复子序列
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:02:32
 * @LastEditTime: 2020-04-01 21:02:32
 */

/*
	for (int i = 0, j = 0; i < n; i ++ )
{
    while (j < i && check(i, j)) j ++ ;

    // 具体问题的逻辑
}
常见问题分类：
    (1) 对于一个序列，用两个指针维护一段区间
    (2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作
*/

/*
	对于本题，开一个数组 s 记录当前 j~i 区间内每个元素的个数
	本质原理：该序列不可能存在重复的元素，所以可以理解为整个序列必出现在
	所有重复的元素 之间，类似于插入排列的思想。
	当 i 到下一个元素时候突然出现和该区间内的元素有重复，
	那么 j 就要跳到 这个重复的元素下一个位置。
*/
#include <iostream>
using namespace std;

const int N = 100010;

int a[N],s[N];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = 0;
    for(int i = 0, j = 0; i < n; i++){
        s[a[i]]++;
        while(s[a[i]] > 1){
            s[a[j]] -- ;
            j++;   // j 跳到下一个元素，直到当前区间没有重复元素
            //j往后走的时候，把掠过的要标记为0，因为这些元素已经不在j - i的区间内了
        }
        res = max(res, i - j + 1);
    }
    printf("%d", res);
    
    return 0;
}