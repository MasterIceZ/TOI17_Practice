#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
ll dp[555][555];

int main(){
	dp[0][0] = 1;
	for(int i=1; i<=500; ++i){
		for(int j=1; j<=500; ++j){
			for(int k=1; k<j; ++k){
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}
	ll q;
	scanf("%lld", &q);
	while(q--){
		scanf("%lld %lld", &a, &b);
		ll sum = 0;
		for(int i=1; i<=b; ++i){
			
		}
		printf("%lld", sum % MOD);
	}
	return 0;
}
