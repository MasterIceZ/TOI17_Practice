/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Pager
 * ALGO		: Dynamic Programming
 * DATE		: 14 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll a[222], b[222], c[222];
ll dp[444][444], cost[444][444];

ll divide(ll l, ll r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l + 1 == r){
		return dp[l][r] = cost[l][r];
	}
	ll nax = INT_MIN;
	for(int k=l+1; k<r; ++k){
		nax = max(nax, divide(l, k) + divide(k, r));
	}
	return dp[l][r] = nax + cost[l][r];
}

void solve(){
	memset(dp, -1, sizeof dp);
	memset(cost, 0, sizeof cost);
	int n;
	cin >> n;
	unordered_map<ll, ll> mp;
	vector<ll> g;
	for(int i=0; i<n; ++i){
		cin >> a[i] >> b[i] >> c[i];
		if(mp[a[i]] != 1){
			mp[a[i]] = 1;
			g.push_back(a[i]);
		}
		if(mp[b[i]] != 1){
			mp[b[i]] = 1;
			g.push_back(b[i]);
		}
	}
	sort(all(g));
	int cnt = 0;
	for(auto x: g){
		mp[x] = cnt++;
	}
	for(int i=0; i<n; ++i){
		cost[mp[a[i]]][mp[b[i]]] = c[i];
	}
	cout << divide(0, cnt-1);
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
