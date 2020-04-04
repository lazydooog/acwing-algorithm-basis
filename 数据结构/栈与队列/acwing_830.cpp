/*
* @Description: 830. 单调栈
* @Author: Xiaobin Ren
* @Date:   2020-04-04 20:22:39
* @Last Modified time: 2020-04-04 20:27:41
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


const int N = 100010;
int tt = 0, stk[N];
int n;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	scanf("%d" ,&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		while(tt && stk[tt] >= x) tt--;
		if(tt) cout << stk[tt] << ' ';
		else cout << -1 << ' ';
		stk[++tt] = x;
	}	
	return 0;
}