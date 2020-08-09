/*
* @Description: 
* @Author: Xiaobin Ren
* @Date:   2020-08-09 16:10:59
* @Last Modified time: 2020-08-09 16:11:07
*/
#include <iostream>
using namespace std;

const int N = 100010;
int h[N], hp[N], ph[N], sz;

void heap_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

int main(){
    int n; int  m;  //m储存当前是第几个插入的数
    cin >> n;
    string s; int x; int k;
    while(n --){
        cin >> s;
        if(s == "I"){
            cin >> x;
            sz++;
            m++;
            ph[m] = sz;
            hp[sz] = m;
            h[sz] = x;
            up(sz);
        }else if (s == "PM"){
            cout << h[1] << endl;
        }else if(s == "DM"){
            heap_swap(1, sz);
            sz -- ;
            down(1);
        }else if(s == "D"){
            cin >> x;
            x = ph[x];
            heap_swap(x, sz);
            sz --;
            down(x), up(x);
        }else{
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    
    return 0;
}