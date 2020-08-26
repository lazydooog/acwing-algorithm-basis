/*
* @Description: 148. 合并果子
* @Author: Xiaobin Ren
* @Date:   2020-08-26 14:24:35
* @Last Modified time: 2020-08-26 14:24:41
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int> > heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    int res = 0;
    while(heap.size() > 1){  //注意此处堆内元素个数不为0
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res = res + a + b;
        heap.push(a + b);
    }
    
    cout << res << endl;
    
    return 0;
}