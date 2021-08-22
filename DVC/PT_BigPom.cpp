/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Big Pom
 * ALGO		: Divide and Conquer
 * DATE		: 21 Aug 2021
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

ll r, s, c;
ll a[100100];

ll divide(ll L, ll R){
	ll lb = lower_bound(a + 1, a + c + 1, L) - (a + 1);
	ll ub = upper_bound(a + 1, a + c + 1, R) - (a + 1);
	ll amount = ub - lb;
	if(amount == 0){
		return r;
	}
	ll ans =  s * (ub - lb) * (R - L + 1);
	if(L == R){
		return ans;
	}
	ll mid = (L + R) >> 1;
	return min(ans, divide(L, mid) + divide(mid + 1, R)); 
}

void solve(){
	ll n;
	cin >> n >> c >> r >> s;
	for(ll i=1; i<=c; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + c + 1);
	cout << divide(1, (1 << n));
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
