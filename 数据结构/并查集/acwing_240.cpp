/*
* @Description: 240. 食物链
* @Author: Xiaobin Ren
* @Date:   2020-08-09 22:15:29
* @Last Modified time: 2020-08-09 22:15:44
*/
#include <iostream>
using namespace std;

/*
    思路 ： 维护到根节点的距离的并查集 路径压缩时候会更新距离 
    
    
    维护距离：
        因为物种是3类 所以将节点到根节点的距离模3 分为3类
        如果 取模之后为0 那么就和根节点同类
        取模之后为1 就 吃根节点 取模之后为 2 就环形接上 被根节点吃 同时吃 1 节点 
        
        解决的过程 就是要把所有节点都合并到同一个集合里面 最终，
        因为任意2节点和根节点的距离 ，模3就可以知道这俩节点的关系
        
        在合并的过程中 分为两节点已经在一起 而且已经是同类的话 就判断距离。
        是同类 而且不在一个集合 那么就合并。
        
        对于x 吃 y 的关系 同样如果在同一个集合 那么必须距离满足模3 大小差1 的条件 不然就是假话
        不在同一个集合 那就合并 同时维护满足关系的距离条件即可
*/

const int N =  50010;
int p[N], d[N];

int n, m;

int find(int x){

    if(x!= p[x]){
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        d[i] = 0; //可以不写 全局变量默认
    }
    
    int res = 0;
    while(m --){
        int t, x, y;
        cin >> t >> x >> y;
        
        if(x > n || y > n) res ++;
        else{
            int px = find(x), py = find(y);
            if(t == 1){  // x y 同类
                if(px == py && (d[x] - d[y]) % 3)  res ++;  //同类但是模3距离不同 则矛盾 假话
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }else{ // x 吃 y 
                if(px == py && (d[x] - d[y]  -1) % 3) res ++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
        
    }
    cout << res << endl;
    
    return 0;
}