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
	int cnt = 0, nax = -1;
	unordered_map<int, int> mp;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x]++;
		while(mp[x] >= 2){
			mp[x] -= 2;
			++x;
			mp[x]++;
			nax = max(nax, x);
		}
		nax = max(x, nax);
	}
//	cout << mp.size() << endl;
//	cnt = 0;
//	for(int i=0; i<=nax; ++i){
//		cout << mp[i] << " ";
//		if(!mp[i]){
//			++cnt;
//		}
//	}
//	cout << cnt ;
	cout << nax;
	cout << mp.size();
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
