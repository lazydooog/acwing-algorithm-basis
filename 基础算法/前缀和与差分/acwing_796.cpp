/*
 * @Description: 796. 子矩阵的和
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:01:24
 * @LastEditTime: 2020-04-02 20:53:40
 */

/*二维前缀和：
    s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];

    S[i, j] = 第i行j列格子左上部分所有元素的和
    以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
    S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]

    这里的子矩阵的和要注意边界的行和列，所以要左上角的上和左都要偏移一个，不要把边界减掉了
*/

#include <iostream>
using namespace std;
int n, m, q;
const int N = 1010;
int s[N][N], a[N][N];
int main(){
    scanf("%d%d%d" ,&n, &m, &q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++)
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];
   while(q--){
       int x1, y1, x2, y2;
       scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
       printf("%d\n", s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
   }
   
   return 0;
}