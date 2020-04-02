/*
 * @Description: 798. 差分矩阵
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:01:40
 * @LastEditTime: 2020-04-02 22:59:26
 */

/*
    给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：
    S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c

*/
#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N], b[N][N];
int n,m,q;

//insert 函数是构造差分矩阵的核心 但是理解比较抽象
void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] +=c;
    b[x2+1][y1] -=c;
    b[x1][y2+1] -=c;
    b[x2+1][y2+1] +=c;
    
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        scanf("%d", &a[i][j]);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        insert(i, j, i, j, a[i][j]);
        
    while(q--){
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    
    for(int i = 1; i <=n; i++)
        for(int j = 1; j <= m; j++)
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(j == m) printf("%d\n", b[i][j]);
            else printf("%d ", b[i][j]);
            
    return 0;
}