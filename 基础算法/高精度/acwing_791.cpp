/*
 * @Description: 791. 高精度加法
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:00:12
 * @LastEditTime: 2020-04-02 10:35:41
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e6 + 10;

vector<int> add(vector<int> &a, vector<int> &b){
    vector<int> c;  //答案
    int t = 0;  //进位标记
    for(int i = 0; i< a.size() || i<b.size(); i++){
        if(i < a.size()) t+=a[i];
        if(i < b.size()) t+=b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(1);
    return c;
}

int main(){
    string a,b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i>=0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i>=0; i--) B.push_back(b[i] - '0');
    auto c = add(A, B);
    for(int i = c.size() - 1; i>=0; i--) printf("%d",c[i]);
}