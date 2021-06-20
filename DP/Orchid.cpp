/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Orchid
 * ALGO		: Dynamic Programming
 * DATE		: 17 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int dp[1000100];

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &x: a){
		cin >> x;
	}
	int sz = 0;
	for(int i=0; i<n; ++i){
		int idx = upper_bound(dp, dp + sz, a[i]) - dp;
		dp[idx] = a[i];
		if(idx == sz){
			++sz;
		}
	}
	cout << n - sz;
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
