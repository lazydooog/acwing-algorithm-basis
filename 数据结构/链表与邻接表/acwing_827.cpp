/*
* @Description: 827. 双链表
* @Author: Xiaobin Ren
* @Date:   2020-04-04 19:45:46
* @Last Modified time: 2020-04-04 19:47:19
*/

#include <iostream>
using namespace std;

const int N = 100010;
int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    //0是左端点，1是右端点，端点不是节点，是边界
    r[0] = 1, l[1] = 0;
    idx = 2; //注意初始化的时候 idx已经是 2 了，相当于已经有两个端点了
}

// 在节点k的右边插入一个数x
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx ++ ;
}

// 删除节点k
void remove(int k)
{
    l[r[k]] = l[k];  //这两句是没有先后关系的
    r[l[k]] = r[k];
}

int main(){
    int m; scanf("%d", &m);
    int x, k;
    string op;
    init();
    while(m -- ){
        cin >> op;
        if(op == "D"){
            cin >> k; 
            remove(k + 1);
        }
        else if(op == "IR"){
            cin >> k >> x;
            add(k+1, x);
        }
        else if(op == "IL"){
            cin >> k >> x;
            add(l[k+1], x);
        }
        else if(op == "L"){
            cin >> x;
            add(0, x);
        }
        else{
            cin >> x;
            add(l[1], x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]){
        cout << e[i] << ' ';
    }
    cout << endl;
    
    return 0;
}






