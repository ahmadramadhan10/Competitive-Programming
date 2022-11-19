#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 2e6 + 5;
const long long mod = 1e9 + 7;
const long long inf = 2e9;

string s;
ll n, m, k;
ll a[40][40];
vector<ll>res;
bool vis[40][40];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, ll tot){
  if(!(1 <= x && x <= n && 1 <= y && y <= m)) return;
  if(vis[x][y]) return;
  tot += a[x][y];
  if(x == n && y == m) {
    res.push_back(tot);
  } else {
    vis[x][y] = true;
    for(int i = 0; i < 4; ++i) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      dfs(nx,ny,tot);
    }
    vis[x][y] = false;
  }
}

int32_t main() {
  cin >> s >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  dfs(1,1,0);
  sort(res.begin(),res.end());
  cin >> k;
  while(k--) {
    ll i, j;
    cin >> i >> j;
    i = lower_bound(res.begin(),res.end(),i) - res.begin();
    j = upper_bound(res.begin(),res.end(),j) - res.begin();
    cout << j-i << '\n';
  }
}
