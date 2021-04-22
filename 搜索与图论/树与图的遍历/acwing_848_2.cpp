#include <bits/stdc++.h>
using namespace std;


//拓扑排序手写队列实现

const int N = 1e5 + 10;
int n, m;
int h[N], d[N], ne[N], e[N], idx;
int q[N];
int path[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort() {
  //初始队列没有元素 tt = -1
  //如果有一个就是tt = 0
  //手写队列这个很坑要注意
  int hh = 0, tt = -1;
  for (int i = 1; i <= n; i++)
    if (d[i] == 0) q[++tt] = i;
  int cnt = 0;
  while (hh <= tt) {
    int t = q[hh++];
    path[cnt++] = t;

    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (--d[j] == 0) q[++tt] = j;
    }
  }
  return cnt == n;
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m --) {
    int a, b;
    cin >> a >> b;
    add(a, b); d[b]++;
  }
  if (topsort()) {
    for (int i = 0; i < n; i++) cout << path[i] << ' ';
    cout << endl;
  } else cout << - 1 << endl;

  return 0;
}