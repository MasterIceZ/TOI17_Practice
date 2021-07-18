/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Coin Change Min
 * ALGO		: Dynamic Programming
 * DATE		: 16 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[1010], dp[1000100];
void solve(){
	int n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1; i<=x; ++i){
		for(int j=1; j<=n; ++j){
			if(i - a[j] >= 0){
				dp[i] = min(dp[i], 1 + dp[i-a[j]]);
			}
		}
	}
	cout << (dp[x] >= 1e9 ? 0: dp[x]);
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
