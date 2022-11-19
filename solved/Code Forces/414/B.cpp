#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 9;
const long long mod = 1000000007;

long long dp[2009][2009], n, m;

void solve(int tc) {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		dp[i][1] = 1;
	}
	for(int i = 2; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= sqrt(j); ++k){
				if(j % k == 0){
					dp[j][i] = (dp[j][i] + dp[k][i-1]) % mod;
					if(k * k != j) dp[j][i] = (dp[j][i] + dp[j/k][i-1]) % mod;
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = (ans + dp[i][m]) % mod;
	}
	cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);

  int TT = 1;
  //cin >> TT;
  for(int tc = 1; tc <= TT; ++tc) {
    solve(tc);
  }

  return 0;
}
