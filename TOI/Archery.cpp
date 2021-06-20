/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Archery TOI15
 * ALGO		: Dynamic Programming
 * DATE		: 19 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll qs[500100], qs2[500100];
pair<ll, ll> a[500100];

void solve(){
	ll n;
	cin >> n;
	ll mkr = LLONG_MAX;
	for(ll i=1; i<=n; ++i){
		cin >> a[i].second;
		mkr = min(mkr, a[i].second);
	}
	for(ll j=1; j<=n; ++j){
		cin >> a[j].first;
	}
	sort(a + 1, a + n + 1);
	for(ll i=1; i<=n; ++i){
		qs[i] += qs[i-1] + a[i].first;
		qs2[i] += qs2[i-1] + a[i].second;
	}
	ll ans = LLONG_MAX, id = -1;
//	cout << mkr << endl;
	for(ll i=1; i<=n; ++i){
		if(a[i].first > mkr){
			break;
		}
		// i -> mid
		// r = mid -> right
		ll r = qs[n] - qs[i] - (n-i) * a[i].first;
		// l = left -> mid
		ll l = qs[i-1] + qs2[i-1] - (i-1) * a[i].first;
		ll sum = l + r;
		if(sum < ans){
			ans = sum;
			id = a[i].first;
		}
	}
	cout << id << " " << ans;
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
