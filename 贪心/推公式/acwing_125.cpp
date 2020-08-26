/*
* @Description: 125. 耍杂技的牛
* @Author: Xiaobin Ren
* @Date:   2020-08-26 15:18:10
* @Last Modified time: 2020-08-26 15:18:43
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 50050;
typedef pair<int, int> PII;
int n;
PII cows[N];

//按照每个牛的 wi + si  排序 然后扫描一遍 
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int w,  s;
        cin >> w >> s;
        cows[i]  = {w + s, s};
    }
    sort(cows, cows + n);
    
    int sum = 0, res = INT_MIN;
    for(int i = 0; i < n; i++){
        res = max(res, sum - cows[i].second);
        sum += cows[i].first - cows[i].second;
    }
    
    cout << res << endl;
    return 0;
}