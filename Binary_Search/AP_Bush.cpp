/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Bush
 * ALGO		: Binary Search
 * DATE		: 31 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll a[1010];

void solve(){
	ll n, k;
	cin >> n >> k;
	for(ll i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l, r;
	l = 0, r = 1e9;
	while(l < r){
		ll mid = (l + r) / 2;
		ll cou = (mid + 1) * (mid + 1) * n;
		for(ll i=2; i<=n; ++i){
			if(a[i] == a[i-1]){
				cou -= (mid + 1) * (mid + 1);
				continue;
			}
			ll dist = a[i] - a[i-1] - 1;
			ll dm = dist / 2;
			if(dm < mid){
				ll o = mid - dm;
				if(dist % 2){
					cou -= o*o;
				}
				else{
					cou -= o*(o + 1);
				}
			}
		}
		if(cou < k){
			l = mid +1;
		}
		else{
			r = mid;
		}
	}
	cout << r ;
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
