/*
* @Description: 826 单链表
* @Author: Xiaobin Ren
* @Date:   2020-04-04 17:24:56
* @Last Modified time: 2020-04-04 19:50:11
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
int head, e[N], ne[N], idx;

//初始化
void init(){
	head = -1;
	idx = 0;
}
//将 x 插到头节点
void add_to_head(int x){
	e[idx] = x, ne[idx] = head, head = idx++;
}

//将 x 插到下标是 k 的点后边
void add(int k, int x){
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}

//将下标是 k 后边的节点删除
void remove(int k){
	ne[k] = ne[ne[k]];
}

int main(){
	int m; read(m);
	init();

	while(m--){
		int k,  x;
		char op;
		cin >> op;
		if(op == 'H'){ read(x); add_to_head(x); }
		else if(op == 'D'){
			 cin >> k;
			 if(!k) head = ne[head];
			 remove(k - 1); 
		}
		else{cin>> k >> x; add(k - 1, x);}
	}
	for(int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
	printf("\n");

	return 0;
}















