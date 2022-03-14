#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define pb push_back
#define ms memset
#define fi first
#define se second
ll MOD = 998244353;
 
ll power(ll base, int n){
    if (n == 0) return 1;
    if (n == 1) return base;
    ll halfn  = power(base, n/2);
    if (n % 2 == 0) return (halfn * halfn) % MOD;
    return (((halfn * halfn) % MOD) * base) % MOD;
}
 
ll inverse(int n){
    return power(n, MOD-2);
}
 
const int N = 200001;
vi g[N], dist(N), p(N), sz(N);
vector<ll> s(N);
void dfs1(int u){
    sz[u] = 1;
    for (int v : g[u]){
        if (p[u] == v) continue;
        p[v] = u;
        dist[v] = dist[u] + 1;
        dfs1(v);
        sz[u] += sz[v];
    }
}
 
void dfs2(int u){
    for (int v : g[u]){
        if (p[u] == v) continue;
        s[v] = s[u] - 2*sz[v] + sz[1];
        dfs2(v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1);
    for (int i = 1; i <= n; i++){
        s[1] += dist[i];
    }
    dfs2(1);
    for (int i = 1; i <= n; i++){
        cout << s[i] << '\n';
    }
    return 0;
}
