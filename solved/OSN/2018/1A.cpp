#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long inf = 2e9;

string subprob;
int n, k;
long long fc[maxn], h[maxn];
long long lu[maxn], ld[maxn], lm[maxn], ru[maxn], rd[maxn], rm[maxn];

void pre_comp(int N){
  fc[0] = 1;
  for(int i = 1; i <= N; ++i) {
    fc[i] = fc[i-1] * i % mod;
  }
  return;
}

int32_t main() {
  cin >> subprob >> n >> k;
  pre_comp(n);
  for(int i = 1; i <= k; ++i) { // input jembatan
    cin >> h[i];
  }
  for(int i = 1; i <= n; ++i) { 
    int e; cin >> e;
    if(h[e] == i) lm[h[e]]++;
    else if(h[e] > i) ld[h[e]]++;
    else lu[h[e]]++;
  }
  for(int i = 1; i <= n; ++i) {
    int e; cin >> e;
    //cout << h[e] << ' ' << i << '\n';
    if(h[e] == i) rm[h[e]]++;
    else if(h[e] > i) rd[h[e]]++;
    else ru[h[e]]++;
  }
  long long ans = 1;
  for(int i = 1; i <= k; ++i) {
    int cur = h[i];
   // cout << cur << '\n';
    long long tot = lu[cur] + lm[cur] + ld[cur];
    if(lu[cur] == rd[cur]) {
      if(lm[cur] == rm[cur] && lm[cur] == 1) { 
        int a = lu[cur];
        int b = rd[cur];
        ans = ans * fc[a] % mod * fc[b] % mod * tot % mod;
      } else {
        ans = ans * fc[lu[cur]] % mod * fc[tot-lu[cur]] % mod;
      }
    } else {
      if(lu[cur] < rd[cur]) {
        if(lu[cur] + lm[cur] == rd[cur]) {
          ans = ans * fc[lu[cur] + lm[cur]] % mod * fc[ld[cur]] % mod;
        } else {
          ans = 0;
        }
      } else {
        if(lu[cur] == rd[cur] + rm[cur]) {
          ans = ans * fc[lu[cur]] % mod * fc[ru[cur]] % mod;
        } else {
          ans = 0;
        }
      }
    }
  }
  cout << ans << '\n';
  return (0-0);
}
