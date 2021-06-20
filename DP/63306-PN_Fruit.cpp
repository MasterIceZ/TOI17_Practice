/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Fruit
 * ALGO		: Dynamic Programming
 * DATE		: 17 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	ll n;
	cin >> n;
	vector<ll> v(n+1), dp(n+2);
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		v[i] += v[i-1];
	}
	int sz = 0, idx;
	for(int i=1; i<=n; ++i){
		if(v[i] <= 0){
			continue;
		}
		idx = lower_bound(dp.begin(), dp.begin() + sz, v[i]) - dp.begin();
		sz += (idx == sz);
		dp[idx] = v[i];
	}
	cout << idx + 1;
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
