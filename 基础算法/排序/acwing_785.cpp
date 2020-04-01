/*
 * @Description: Acwing 785. 快速排序
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 18:18:52
 * @LastEditTime: 2020-04-01 18:19:48
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a; i< n; i++)
#define per(i,a,n) for(int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res+=a%mod;a+=a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head


void quick_sort(int *q, int l, int r){
    if (l >= r) return ;
    int i = l - 1, j = r + 1, x = q[l + ((r - l) >> 1)];
    while(i < j){
        do i++; while (q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j); quick_sort(q, j+1, r);
}

int main(){
    int n, i = 0;
    scanf("%d", &n);
    int a[100005];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quick_sort(a, 0, n-1);
    for(int i = 0; i < n; i++) printf("%d ",a[i]);
    
    return 0;
}
