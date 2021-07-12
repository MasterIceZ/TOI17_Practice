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

bool check(string s){
	string t = s;
	reverse(s.begin(), s.end());
	return s == t;
}

void solve(){
	string s;
	cin >> n >> s;
//	cout << n << endl;
	if(n > 10000){
		return ;
	}
	for(int sz=1; sz<=n; ++sz){
		int cnt = 0;
		for(int i=0; i+sz - 1<n; ++i){
			if(check(s.substr(i, sz))){
				++cnt;
			}
//			cout << s.substr(i, sz) << endl;
		}
		cout << cnt << endl;
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << "\n";
	}
	return 0;
}
