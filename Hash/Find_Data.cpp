/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Find Data
 * ALGO		: Hash Table
 * DATE		: 22 Aug 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const ll MOD = 99999989;
const int Hash = 1e7 + 19;
ll table[Hash];

ll power[4][5555];

void solve(){
	ll a, b, n, m, x;
	cin >> a >> b >> n >> m;
	for(ll i=0; i<=5000; ++i){
		power[0][i] = (i * i) % MOD;
		power[1][i] = (power[0][i] * i) % MOD;
	}
	for(int i=0; i<a; ++i){
		cin >> x;
		for(int j=0; j<b; ++j){
			ll num = (x + power[0][j]) % MOD;
			ll key = num % Hash;
			while(table[key]){
				key = (key + 1) % Hash;
			}
			table[key] = num;
		}
	}
	ll ans = 0;
	for(int i=0; i<n; ++i){
		cin >> x;
		for(int j=0; j<m; ++j){
			ll num = (x + power[1][j]) % MOD;
			ll key = num % Hash;
			while(table[key]){
				if(table[key] == num){
					++ans;
					break;
				}
				key = (key + 1) % Hash;
			}
		}
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
