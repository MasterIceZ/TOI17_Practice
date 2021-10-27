/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi16_wheel
 * ALGO		: Math, Brute Force
 * DATE		: 25 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll __lcm(ll a, ll b){
	return a / __gcd(a, b) * b;
}

char t;
vector<string> v;
vector<ll> lcm;
ll n, ans = LLONG_MAX;

void rec(ll click, int level){
	if(level == n){
		ans = min(ans, click);
		return ;
	}
	for(ll i=0; i<=lcm[level + 1] && i < ans; i+=lcm[level]){
		if(v[level][(i + click) % v[level].size()] == t){
			rec(i + click, level + 1);
		}
	}
}

void solve(){
	string s;
	cin >> n >> t;
	for(int i=1; i<=n; ++i){
		cin >> s;
		v.push_back(s);
	}
	lcm.push_back(1);
	for(auto x: v){
		lcm.push_back(__lcm(lcm.back(), x.size()));
	}
	rec(1, 0);
	cout << ans;
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
