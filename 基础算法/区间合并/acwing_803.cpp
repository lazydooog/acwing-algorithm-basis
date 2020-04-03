/*
 * @Description: 803. 区间合并
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:06:15
 * @LastEditTime: 2020-04-01 21:06:15
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
int n;
vector<PII> segs;

void merge(vector<PII> &segs){
	vector<PII> res;
	sort(all(segs));
	int st  = -2e9, ed = -2e9;  //左右边界，从无限远处过来开始维护
	for(auto seg : segs){
		if (ed < seg.first){
			if (st != -2e9) res.push_back({st, ed});
			st = seg.first, ed = seg.second; //第一次循环就是从第一个区间开始维护
		}
		else ed = max(ed, seg.second);
	}
	//注意这个循环逻辑:先拿当前的维护区间和下一个区间比较，再push_back,所以最后一个区间
	//的时候，压进去的是上一个区间，或者继续把最后一个区间也合并进去，所以要再压一次
	if(st != -2e9) res.push_back({st, ed});  //最后一个区间，同时判断是否为空区间
	segs = res;
}

int main(int argc, char const *argv[])
{
	read(n);
	rep(i,0,n){
		int l, r;
		scanf("%d%d", &l, &r);
		segs.push_back({l, r});
	}
	merge(segs); printf("%d", segs.size());

	return 0;
}