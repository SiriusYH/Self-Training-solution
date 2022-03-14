#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long double ld;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define ms memset
#define pb push_back
#define F first
#define S second
ll MOD = 998244353;
 
ll power(ll base, ll n){
	if (n == 0) return 1;
	if (n == 1) return base;
	ll halfn = power(base, n/2);
	if (n % 2 == 0) return (halfn * halfn) % MOD;
	return (((halfn * halfn) % MOD) * base) % MOD;
}
 
ll inverse(ll n){
	return power(n, MOD-2);
}
 
ll add(ll a, ll b){
	return (a+b) % MOD;
}
 
ll mul(ll a, ll b){
	return (a*b) % MOD;
}
 
ll gcd(ll a, ll b){
	if (a == 0) return b;
	if (a == 1) return 1;
	return gcd(b % a, a);
}
 
const int N = 100001;
vi g[N], p(N);
ll dp[N][2];
vector<ll> l(N), r(N);
 
void dfs(int u){
	dp[u][0] = 0;
	dp[u][1] = 0;
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if (p[u] == v) continue;
		p[v] = u;
		dfs(v);
		dp[u][0] += max(dp[v][0] + abs(l[v]-l[u]), dp[v][1] + abs(r[v]-l[u]));
		dp[u][1] += max(dp[v][0] + abs(l[v]-r[u]), dp[v][1] + abs(r[v]-r[u]));
	}
}
int main(){
	ios::sync_with_stdio(false);
	int TC; cin >> TC;
	while(TC--){
		int n; cin >> n;
		p.resize(n+1);
		l.resize(n+1); r.resize(n+1);
		FOR(i, 1, n+1){
			cin >> l[i] >> r[i];
		}
		FOR(i, 0, n-1){
			int u, v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		}
		dfs(1);
		cout << max(dp[1][0], dp[1][1]) << '\n';
		FOR(i, 1, n+1){
			g[i].clear();
		}
	}
	return 0;
}
 
 
