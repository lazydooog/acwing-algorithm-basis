/*
* @Description: 338. 计数问题
* @Author: Xiaobin Ren
* @Date:   2020-08-25 19:58:47
* @Last Modified time: 2020-08-25 20:02:26
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

//计算每个数字 在所有数字的每一位上出现的次数 然后累加起来即可 
//数位Dp 分类讨论
int a, b;

int get(vector<int> num, int l, int r){  //求前面这些位数组成的 数字 是多大 下标从右到左递增
    int res = 0;
    for(int i = l; i >= r; i--)
        res = res * 10 + num[i];
        
    return res;
}

int power(int i){  //计算10 ^ i
    int res =1;
    while(i --) res *= 10;
    
    return res ; 
}

int count(int n, int x){  //统计 1 ~ n 里面有多少个 x 题目的a ,b 范围都是正整数 注意
    if(!n) return 0;
    vector<int> num;
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size(); //数字n的位数
    //假设数字为 abc d efg  分为 d前面的 < abc  以及等于  abc 讨论 
    int res = 0;
    
    for(int i = n - 1 - !x; i >= 0; i --){ //从最高位枚举 计数 当x == 0时候就从第二位开始枚举 因为最高位n - 1不可能是0
        if(i < n - 1) {
            res += get(num, n - 1, i + 1) * power(i); //计算 i 前面的数字  注意vector存放的数字是反的
            if(x == 0) res -= 1 * power(i); //当 d 是 0 的时候 则abc 最小为001  因为不能有前导0 不合法 减去这种不合法的数量
        }
        
        if(num[i] == x) res += get(num, i - 1, 0) + 1; // d == x 
        else if(num[i] > x) res += power(i);  //d > x
    }
    
    return res;
}

int main(){
    while(cin >> a >> b && (a || b)){
        if(a > b) swap(a, b);
        for(int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    
    return 0;
}
