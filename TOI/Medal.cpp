/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Medal TOI15
 * ALGO		: Greedy
 * DATE		: 19 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<ll> v(n), w(n);
	for(auto &x: v){
		cin >> x;
	}
	for(auto &x: w){
		cin >> x;
	}
	sort(all(v));
	sort(all(w), greater<ll>());
	ll ans = 0;
	for(int i=0; i<n; ++i){
		v[i] += w[i]; 
	}
	sort(all(v));
	for(int i=1; i<n; ++i){
		ans += v[i] - v[i-1];
	}
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
