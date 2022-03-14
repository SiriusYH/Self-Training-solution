#include <bits/stdc++.h>
using namespace std;

int const N=90+3;
long long dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	dp[1]=1;
	dp[2]=1;
	for (int i=(3); i < (N); ++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	while(1){
		int n;
		cin>> n;
		cout<<dp[n]<<endl;
	}
	return 0;
} 
