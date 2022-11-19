#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9+7;
const long long inf = 2e9;
 
ll dp[maxn][105], a[maxn];
ll n, m;

int main() { 
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; ++i) {
    dp[0][i] = 1;
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i] != 0) {
      dp[i][a[i]] = dp[i-1][a[i]];
      if(i > 1) {
        if(a[i] > 1) dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]-1]) % mod;
        if(a[i] < m) dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]+1]) % mod;
      }
    } else {
      for(int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i-1][j];
        if(i > 1){
          if(j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
          if(j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 1; i <= m; ++i) {
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans;
}
