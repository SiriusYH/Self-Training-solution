#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long double ld;
typedef pair<pair<ll, ll>, pair<ll, ll>> lll;
 
#define pb push_back
#define ms memset
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
 
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
 
 
 
ll gcd(ll a, ll b){
    if (a == 0) return b;
    if (a == 1) return 1;
    return gcd(b % a, a);
}
 
ll lcm(ll a, ll b){
    return (a * b) / gcd(a, b);
}
 
const int N = 200001;
vector<int> g[N], p(N), sz(N);
 
void dfs(int u){
    sz[u] = 0;
    for (int v : g[u]){
        if (p[u] == v) continue;
        p[v] = u;
        dfs(v);
        sz[u] += sz[v] + 1;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n; 
    for (int i = 2; i <= n; i++){
        int v; cin >> v;
        g[i].pb(v);
        g[v].pb(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << sz[i] << " ";
    cout << '\n';
    return 0;
}
