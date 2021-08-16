/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_EatFast
 * ALGO		: Eat Fast
 * DATE		: 17 Aug 2021
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

void solve(){
	ll n, m, last = -1;
	cin >> n >> m;
	vector<ll> v(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		if(v[i] > 0){
			last = i;
		}
	}
	ll l = 0, r = 1e18;
	while(l < r){
		ll i, mid = (l + r) / 2;
		ll cnt = 1, sum = mid;
		for(i=1; i<=last; ++i){
			sum -= 1;
			while(sum < v[i]){
				cnt += 1, sum += mid - i;
				if(cnt == m + 1){
					break;
				}
			}
			sum -= v[i];
			if(cnt == m + 1){
				break;
			}
		}
		if(i == last + 1){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l ;
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
