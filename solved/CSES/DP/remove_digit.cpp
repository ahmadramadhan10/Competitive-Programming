#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 2e6 + 9;
const int mod = 1e9+7;
const long long inf = 2e9;
 
ll dp[maxn], n;
 
ll DP(ll cur) {
  if(cur < 0) return 0;
  if(dp[cur] != -1) return dp[cur];
  ll temp = cur;
  set<int>st;
  while(temp){
    st.insert(temp%10);
    temp /= 10;
  }
  ll best = 2e9;
  for(auto it : st) {
    if(it != 0) {
      best = min(best, DP(cur - it) + 1);
    }
  }
  return dp[cur] = best;
}
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin >> n;
  memset(dp,-1,sizeof dp);
  dp[0] = 0;
  ll ans = DP(n);
  cout << ans;
}
