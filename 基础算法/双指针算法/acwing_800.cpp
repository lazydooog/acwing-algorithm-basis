/*
 * @Description: 800. 数组元素的目标和
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:02:38
 * @LastEditTime: 2020-04-01 21:02:38
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


const int N = 100010;
int a[N], b[N];
int n, m, x;

int main(){
	read(n), read(m), read(x);
	for(int i = 0; i < n; i++) read(a[i]);
	for(int i = 0; i < m; i++) read(b[i]);

	for(int i = 0,j = m-1; i < n; i++){
		while(j > 0 && a[i] + b[j] > x) j--;
		if (j >= 0 && a[i] + b[j] == x) printf("%d %d", i, j);
	}
	return 0;
}













