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
//bottom-up dp
ll const mod=1e9+7;
int const N=1e6+1;
ll dp[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	dp[0]=1;
	FOR(i,1,n+1)
	{
		dp[i]=0;
		FOR(j,1,6+1)
		{
			if(i-j<0)continue;
			dp[i]+=dp[i-j];
			dp[i]%=mod;
			
		}
		
	}
	cout<<dp[n]<<endl;
	return 0;
}











