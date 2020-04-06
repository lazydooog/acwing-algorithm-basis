
/* 837. 连通块中点的数量
* @Description: 
* @Author: Xiaobin Ren
* @Date:   2020-04-06 10:59:10
* @Last Modified time: 2020-04-06 11:22:13
*/

#include <iostream>
using namespace std;

const int N = 100010;
int p[N], size[N];
int n, m;

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
	scanf("%d%d", &n, &m);
	// 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    while(m--){
    	char op[5];
    	int a, b;
		scanf("%s", op);

		if(op[0] == 'C'){
	    	scanf("%d%d", &a, &b);
	    	//如果已经在同一个集合里面，就不用加了 直接continue
	    	if(find(a) == find(b)) continue;

	    	size[find(b)] += size[find(a)];
	    	p[find(a)] = find(b);
		}    	
		else if(op[1] == '1'){
	    	scanf("%d%d", &a, &b);
	    	if(find(a) == find(b)) puts("Yes");
	    	else puts("No");
		}
		else{
			scanf("%d", &a);
			printf("%d\n", size[find(a)]);
		}
    }

	return 0;
}