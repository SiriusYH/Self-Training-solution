#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
 
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
vector<ll> p(200001), g[200001], rt(200001), sum(200001), a(200001), maxi(200001);
void dfs(int u){
	if (g[u].size() == 0){
		sum[u] = a[u];
		rt[u] = 1;
		maxi[u] = a[u];
		return;
	}
	sum[u] = a[u]; rt[u] = 0;
	for (int v : g[u]){
		dfs(v);
		sum[u] += sum[v];
		rt[u] += rt[v];
	}
	maxi[u] = (sum[u] + rt[u] - 1) / rt[u];
	for (int v : g[u]){
		maxi[u] = max(maxi[u], maxi[v]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 2; i <= n; i++){
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	cout << maxi[1] << '\n';
	return 0;
}
