#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long double ld;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ms memset
#define fi first
#define se second
 
ll MOD = 1000000007;
ll A = 998244353;
 
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
 
ll gcd(ll a, ll b){
    if (a == 0) return b;
    if (a == 1) return 1;
    return gcd(b%a, a);
}
 
const int N = 200001;
vector<int> g[N], p(N);
vector<pair<int, int>> dp(N);
// first = vertex used, second = vertex unused
void dfs(int u){
    dp[u] = {0, 0};
    for (int v : g[u]){
        if (p[u] == v) continue;
        p[v] = u;
        dfs(v);
        dp[u].second += max(dp[v].first, dp[v].second);
    }
    dp[u].first = dp[u].second;
    for (int v : g[u]){
        if (p[u] == v) continue;
        if (dp[v].second >= dp[v].first){
            dp[u].first++;
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1].first, dp[1].second) << '\n';
    return 0;
}
 
