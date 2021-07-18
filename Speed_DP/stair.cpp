/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: stair
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;
int dp[5050];

void solve(){
	int n, mod;
	cin >> n >> mod;
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=n; j>=i; --j){
			dp[j] += dp[j - i];
			dp[j] %= mod;
		}
	}
	cout << dp[n] - 1;
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
