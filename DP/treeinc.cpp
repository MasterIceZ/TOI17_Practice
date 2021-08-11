/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: treeinc
 * ALGO		: Dynamic Programming
 * DATE		: 11 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[300300];
vector<int> adj[300300];

void solve(){
	int n, u, v, nax = -1;
	cin >> n;
	for(int i=1; i<n; ++i){
		cin >> u >> v;
		adj[max(u, v)].push_back(min(u, v));
	}
	for(int i=1; i<=n; ++i){
		for(auto x: adj[i]){
			dp[i] = max(dp[i], dp[x]);
		}
		dp[i] += 1;
		nax = max(dp[i], nax);
	}
	cout << nax;
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
