/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Shootmarble
 * ALGO		: Greedy
 * DATE		: 2 Nov 2021
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

int cnt[22];

void solve(){
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		for(int j=0; j<=20; ++j){
			if((1 << j) & x){
				cnt[20 - j] += 1;
			}
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		ll tmp = 0;
		for(int j=0; j<=20; ++j){
			tmp *= 2;
			if(cnt[j] > 0){
				tmp += 1;
				cnt[j] -= 1;
			}
		}
		dbg(tmp);
		ans += tmp * tmp;
	}
	cout << ans;
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
