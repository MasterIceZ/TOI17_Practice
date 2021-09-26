/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Invermake
 * ALGO		: Dynamic Programming
 * DATE		: 26 Sep 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const ll MOD = 1e9 + 7;
ll dp[3][10010];

void solve(){
	dp[1][0] = 1;
	int n, d;
	cin >> n >> d;
	for(int i=2; i<=n; ++i){ // Insert i to Seq[1...(i - 1)]
		/*
		for(int j=0; j<=min(d, (i * (i - 1) / 2)); ++j){ // Number of Inversion
			for(int k=max(j-i+1, 0); k<=j; ++k){ // Creating i from 1, 2, 3
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= MOD;
			}
		}
		* */
		ll tmp = 0;
		for(int j=0; j<=d; ++j){
			tmp += dp[(i - 1) & 1][j];
			tmp %= MOD;
			if(j >= i){
				tmp -= dp[(i - 1) & 1][j - i];
			}
			tmp += MOD;
			tmp %= MOD;
			dp[i & 1][j] = tmp;
		}
	}
	cout << dp[n & 1][d];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
