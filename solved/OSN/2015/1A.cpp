#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
string str;
ll sd, td, ls, lt, n;
ll sb, tb, bu_sd, bu_td;
ll l, r, mid, best;
ll st, tt, le, ri;
vector<pair<ll,ll>>need;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> str;
  cin >> sd >> td >> ls >> lt >> n;
  cin >> sb >> tb; 
  for(int i = 2; i <= n; i++) {
    ll s,t;
    cin >> s >> t;
    l = 0, r = 1LL * N;
    while(l <= r) {
      mid = (l + r) / 2;
      st = sd + (ls * mid);
      tt = td + (lt * mid);
      le = s / tt;
      ri = st / t;
      if(s % tt) ++le;
      if(st % t) ++ri;
      if(le <= ri) {
        best = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }  
    }
    need.push_back({best,i * 1LL});
  }
  sort(need.begin(),need.end());
  l = 0, r = 1LL * N;
  while(l <= r) {
    mid = (l + r) / 2;
    st = sd + (ls * mid);
    tt = td + (lt * mid);
    le = sb / tt;
    ri = st / tb;
    if(sb % tt) ++le;
    if(st % tb) ++ri;
    if(le <= ri) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if(best > n - 1) {
    cout << -1;
    return 0;
  }
  vector<int>ans;
  int butuh = 0;
  for(int i = 0; i < n - 1; i++) {
    if(ans.size() == best) {
      break;
    }
    if(need[i].first <= butuh) {
      ans.push_back(need[i].second);
      butuh++;
    } 
  }
  if(ans.size() != best) {
    cout << -1;
  } else {
    cout << ans.size() << '\n';
    for(auto it : ans) cout << it << '\n';
  }
}
