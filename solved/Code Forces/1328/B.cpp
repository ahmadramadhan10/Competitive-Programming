#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 9;
const long long mod = 1e9 + 7;
const long long inf = 2e9;
 
// n-2 char a, and two char b, lexicography
long long C(long long x){
	return x * (x-1) / 2LL;
}
 
void solve(int tc) {
	long long n, k;
	cin >> n >> k;
	string s = "";
	for(int i = 0; i < n; ++i) s.push_back('a');
	long long l = 1, r = inf, mid, best = -1;
	while(l <= r){
		mid = (l + r) >> 1;
		if(k <= C(mid)) {
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	s[n-best] = 'b';
	best = k - C(best-1);
	s[n-best] = 'b';
	cout << s << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0);
 
	int TT = 1;
	cin >> TT;
	for(int tc = 1; tc <= TT; ++tc){
		solve(tc);
	}
}
 
