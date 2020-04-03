/*
 * @Description: 801. 二进制中1的个数
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:05:44
 * @LastEditTime: 2020-04-01 21:05:45
 */

/*
	求n的二进制表示中 第k位(从右到左）数字: n >> k & 1
	返回n的最后一位1：lowbit(n) = n & -n
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
#define read(x) scanf("%d", &x)
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


//lowbit() 是树状数组的前提
//同时也可以求出一个数字二进制表示有多少个1
//每次减掉 lowbit 每次计数加一，直到减为零

#include <iostream>
using namespace std;

const int N  = 100010;
int a[N];
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        while(a[i]){
          a[i] -= a[i] & -1*a[i]; 
          cnt++;  
        } 
        printf("%d ", cnt);
    }
}

