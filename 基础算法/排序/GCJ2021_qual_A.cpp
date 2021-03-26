#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res = 0; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = (res + a) % mod; a = 2 * a % mod;} return res;}
ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

const int INF = 0x3f3f3f3f;
const int N = 110;
int a[N];

int reverse_s(int a[], int n) {
    int res = 0;
    for (int i = 1; i <= n - 1; i++) {
        int min = INF;
        int pos = 0;
        for (int j = i; j <= n; j++) {
            if (a[j] < min) {
                min = a[j];
                pos = j;
            }
        }
        reverse(a + i, a + pos + 1);
        res += pos - i + 1;
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(a, 0, sizeof a);
        cout << "Case #" << i << ": ";
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << reverse_s(a, n) << endl;
    }


    return 0;
}