#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 2e6 + 5;
const long long mod = 1e9 + 7;
const long long inf = 2e9;

string sb, s;
ll n, m, k, fc[maxn], ifc[maxn];

ll mp(ll a, ll b){
  ll res = 1;
  while(b){
    if(b&1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

void pre_comp(ll N){
  fc[0] = 1;
  for(ll i = 1; i <= N; ++i) {
    fc[i] = fc[i - 1] * i % mod;
  }
  ifc[N] = mp(fc[N],mod-2);
  for(ll i = N-1; i >= 0; i--) {
    ifc[i] = (i + 1) * ifc[i + 1] % mod;
  }
}

ll C(ll a, ll b) {
  return fc[a] * ifc[a-b] % mod * ifc[b] % mod;
}

int main() {
  cin >> sb >> n >> m >> k >> s;
  pre_comp(m);
  ll t = C(m,k);
  ll c = mp(2, m * (n - 1));
  cout << t * c % mod << '\n';
}
