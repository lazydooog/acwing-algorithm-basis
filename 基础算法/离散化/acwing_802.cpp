/*
 * @Description: 802. 区间和
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:06:00
 * @LastEditTime: 2020-04-01 21:06:00
 */

/*
	离散化模板：这是整数保序离散化

	vector<int> alls; // 存储所有待离散化的值
	sort(alls.begin(), alls.end()); // 将所有值排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

	// 二分求出x对应的离散化的值
	int find(int x) // 找到第一个大于等于x的位置
	{
	    int l = 0, r = alls.size() - 1;
	    while (l < r)
	    {
	        int mid = l + r >> 1;
	        if (alls[mid] >= x) r = mid;
	        else l = mid + 1;
	    }
	    return r + 1; // 映射到1, 2, ...n
	}
*/

/*
	其实原理很简答，因为要操作的数组太大开不下，所以就把每次操作的下标
	放入一个vector内，同时用其他结构来储存每次要操作的细节，比如此题的add和query
	去重的目的是将每一个待离散的值，也就是alls数组内的元素，每一个不同的元素唯一隐射
	到a[]数组内，不然二分查找到多个就不唯一了。

	一句话：通过离散化，把alls数组的元素离散到a[]内
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

/*
	注意：这个x操作不一定是有序的，所以要排序，排序的时候
	由于l 和 r 也被压进alls数组，所以会和x下标一起排序
	即使去重了把l和r去掉了也无所谓，因为查到的x的下标和l是一样的下标
	l,r占用了alls的位置，在映射的时候，a[]内也会把这些位置给空出来。
*/
const int N = 300010;
int a[N], s[N];  //s 是前缀和
int n, m;
VI alls; vector<PII> add, query;

int find(int x){
	int l = 0,r = sz(alls) - 1;
	while(l < r){
		int mid = l + ((r - l) >> 1);
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}

int main(int argc, char const *argv[])
{
	read(n), read(m);
	for(int i = 0; i < n; i++){
		int x, c;
		read(x), read(c);
		add.push_back({x, c});
		alls.push_back(x);
	}	

	for(int i = 0; i < m; i++){
		int l, r;
		read(l), read(r);
		query.push_back({l, r});
		alls.push_back(l); alls.push_back(r);
	}
	//去重
	sort(all(alls));
	alls.erase(unique(all(alls)), alls.end());
	for(auto item : add){
		int x = find(item.first);
		a[x] += item.second;
	}
	//前缀和
	for(int i = 0; i <= sz(alls); i++) s[i] = s[i - 1] + a[i];

	//询问
	for(auto item : query){
		int l = find(item.fi), r = find(item.se);
		printf("%d\n", s[r] - s[l -1]);
	}
	return 0;
}

