/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_AVL
 * ALGO		: Dynamic Programming
 * DATE		: 19 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll dp[100100];

void solve(){
	int n;
	cin >> n;
	cout << dp[n];
	return ;
}

const int MOD = 1e8 + 7;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=100000; ++i){
		dp[i] = dp[i-1] + dp[i-2] + 1;
		dp[i] %= MOD;
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
