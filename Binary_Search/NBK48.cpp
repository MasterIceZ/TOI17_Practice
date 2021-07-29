/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: NBK48 TOI14
 * ALGO		: Binary Search
 * DATE		: 29 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> dp;

void solve(){
	int x;
	cin >> x;
	cout << upper_bound(all(dp), x) - dp.begin() - 1;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	dp.resize(n + 1, 0);
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] += dp[i-1];
	}
	for(int i=n-1; i>=1; --i){
		dp[i] = min(dp[i], dp[i+1]);
	}
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
