/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Destroy Bottle
 * ALGO		: Greedy
 * DATE		: 31 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll b[100100], pos[100100], mkr[100100], chk[100100];

void solve(){
	ll n, m, x;
	cin >> n >> m;
	vector<pair<ll, ll>> a(n + 1);
	for(ll i=1; i<=n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	for(ll i=1; i<=n; ++i){
		b[i] = a[i].first;
		pos[i] = a[i].second;
	}
	ll cnt = n;
	for(ll j=1, ans=0; j<=m; ++j, ans=0){
		cin >> x;
		for(ll i=cnt; i>=1; --i){
			if(b[i] <= x){
				cnt = i;
				break;
			}
			if(mkr[pos[i]] && mkr[pos[i]] != j){
				continue;
			}
			if(mkr[pos[i]] != j){
				ans += 1;
				mkr[pos[i]] = j;
			}
			if(pos[i] + 1 <= n && !mkr[pos[i] + 1]){
				ans += 1;
				mkr[pos[i] + 1] = j;
			}
			if(pos[i] - 1 >= 1 && !mkr[pos[i] - 1]){
				ans += 1;
				mkr[pos[i] - 1] = j;
			}
		}
		cout << ans << "\n";
	}
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
