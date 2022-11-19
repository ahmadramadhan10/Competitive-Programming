#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9 + 7;
const long long inf = 2e9;

vector<ll>a[maxn];
vector<ll>pre[maxn];
ll cnt[maxn], dp[maxn];
ll n, m;
string s;

int main() {
  cin >> s >> n >> m;
  vector<pair<ll,ll>>batik(n);
  for(int i = 0; i < n; ++i) {
    cin >> batik[i].second >> batik[i].first;
  }
  sort(batik.begin(),batik.end());
  for(int i = 0; i < n; ++i) {
    int jenis = batik[i].second;
    ll cur = batik[i].first;
    if(i == 0) dp[i] = cur;
    else dp[i] = dp[i-1] + cur;

    if(pre[jenis].size() > 0) {
      int last_idx = pre[jenis].size() - 1;
      cur += pre[jenis][last_idx];
      pre[jenis].pb(cur);
    } else {
      pre[jenis].pb(cur);
    }
  }
  long long ans = 0;
  for(ll i = 0; i < n; ++i) {
    int jenis = batik[i].second;
    if(i > 0) {
      ll cur = (batik[i].first * i) - dp[i - 1]; 
      //cout << cur << " ";
      if(cnt[jenis] > 0) { // bukan paling awal
        cur -= batik[i].first * cnt[jenis] - pre[jenis][cnt[jenis] - 1];
      }
      //cout << batik[i].first << " " << batik[i].second << ' ' << cnt[jenis] << '\n';
      ans += cur;
    }
    ++cnt[jenis];
  }
  cout << ans << '\n';
  return (0-0);
}
