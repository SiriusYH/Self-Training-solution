#include <bits/stdc++.h>
using namespace std;

typedef long double dl;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i=(a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,b)
#define ROF(i,a,b) for (int i=(b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a :x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
//complete search
ll const mod=1e9+7;

ll f(int n)
{
	ll ans=0;
	if(n==0)return 1;
	for(int i=1;i<6+1;++i){
		if(n-i<0)continue;
		ans += f(n-i);
		ans %=mod;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>> n;
	cout<<f(n)<<"\n";
	return 0;
}















