/*
* @Description: 899. 编辑距离
* @Author: Xiaobin Ren
* @Date:   2020-08-22 18:48:16
* @Last Modified time: 2020-08-22 18:48:26
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 15;
const int M = 1010;
//复杂度 1000 * 1000 * 10 * 10 两秒可以过

int n, m;
int f[N][N]; char str[M][N];


int check(char a[], char b[]){
    int la = strlen(a + 1), lb = strlen(b + 1);
    
    for(int i = 0; i <= lb; i++) f[0][i] = i;
    for(int j = 0; j <= la; j++) f[j][0] = j;
    
    for(int i = 1; i <= la; i++)
        for(int j = 1; j <= lb; j++){
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
        
    return f[la][lb];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> str[i] + 1; //从第一位开始读入 注意括号外加一 二维数组
    
    while(m--){
        char s[N];
        int limit;
        cin >> s + 1 >> limit;
        
        int res = 0;  //遍历求答案
        for(int i = 0; i < n; i++)
            if(check(str[i], s) <= limit)
                res ++;
        
        cout << res << endl;
    }
    
    return 0;
}