/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, k;
ll qs[1000100], query[1000100];

void solve(){
	ll x;
	cin >> x;
	memcpy(query, qs, sizeof qs);
	for(int i=k+1; i<=n; ++i){
		ll ult = x + query[i - k] + (qs[i] - qs[i-k])/ 2;
		ll norm = query[i-1] + qs[i] - qs[i-1];
		query[i] = min(norm, ult);
	}
	cout << query[n]; 
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
