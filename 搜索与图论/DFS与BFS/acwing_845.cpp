/*
* @Description: 845. 八数码
* @Author: Xiaobin Ren
* @Date:   2020-08-12 12:30:23
* @Last Modified time: 2020-08-12 12:30:35
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;

int bfs(string start){
    string end = "12345678x";  //最终状态
    queue<string> q;
    unordered_map<string, int> d;
    
    q.push(start);
    d[start] = 0; //起点到起点的距离为0
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0,1,0,-1};
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        
        int dist  = d[t];
        
        if(t == end) return dist;
        
        //状态转移
        int k = t.find('x'); 
        int x = k / 3, y = k % 3;  //  x 在矩阵的坐标
        
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i]; //枚举上下左右的坐标
            if(a >= 0 && a < 3 & b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]); //这里的交换是引用交换 会改变t数组的值 不是浅拷贝
            
                if(!d.count(t)){  //新的状态
                    d[t] = dist + 1;
                    q.push(t);
                }
                
                swap(t[k], t[a * 3 + b]); //恢复状态
            }
        }
        
    }
    
    return -1;  //不存在方案
}

int main(){
    char str[2];
    string start;  //初始状态  
    for(int i = 0; i < 9; i++){ //cin string 遇到空格就会忽略 所以要用 字符串拼接的方式读入
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    
    return 0;
}
