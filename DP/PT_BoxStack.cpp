/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Box Stack
 * ALGO		: Dynamic Programming
 * DATE		: 26 Sep 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

pair<ll, ll> v[1010];
ll dp[1010];

void solve(){
	int n;
	cin >> n;
	for(int i=n; i>=1; --i){
		cin >> v[i].first >> v[i].second;
		dp[i] = 1e9 + 10;
	}
	for(int i=1; i<=n; ++i){
		for(int j=i; j>=1; --j){
			if(v[i].second >= dp[j - 1]){
				dp[j] = min(dp[j], dp[j - 1] + v[i].first);
			}
		}
	}
	for(int i=n; i>=1; --i){
		if(dp[i] != 1e9 + 10){
			cout << i;
			return ;
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
