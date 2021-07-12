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

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;

void solve(){
	cin >> n;
//	unordered_map<ll, int> mp;
	set<ll> s;
	ll nax = 0, x;
	for(int i=1; i<=n; ++i){
		cin >> x;
		if(!s.count(x)){
			s.insert(x);
		}
		else{
			while(s.count(x)){
				s.erase(x);
				++x;
			}
			s.insert(x);
		}
		nax = max(x, nax);
	}
//	cout << s.size() << " ";
//	cout << nax;
	cout << nax - (ll)(s.size()) + 1ll;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
