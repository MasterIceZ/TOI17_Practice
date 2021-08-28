/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

ll qs[5100][5100];

bool square(ll n){
	ll l = 1, r = n;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(mid * mid == n){
			return true;
		}
		if(mid <= n / mid){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return false;
}

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a++, b++, c++, d++;
	cout << qs[c][d] - qs[c][b - 1] - qs[a - 1][d] + qs[a - 1][b - 1];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1, r, c;
	cin >> r >> c >> q;
	if(r >= 5001 || c >= 5001 || q >= 5001){
		return 0;
	}
	vector<ll> a(r + 1), b(c + 1);
	for(int i=1; i<=r; ++i){
		cin >> a[i];
	}
	for(int j=1; j<=c; ++j){
		cin >> b[j];
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			ll now = a[i] * b[j];
//			dbg(i, j, now);
			ll sqn = sqrt(now);
			if(sqn * sqn == now){
				dbg("Found", i, j, sqrt(now), now);
				qs[i][j] += 1;
			}
			qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
		}
	}
	/*
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cout << qs[i][j] - qs[i-1][j] - qs[i][j-1] + qs[i-1][j-1] << " ";
		}
		cout << "\n";
	}
	* */
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
