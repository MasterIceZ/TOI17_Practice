/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Biochemistry
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

void solve(){
	ll n, a, b;
	cin >> n >> a >> b;
	ll l = 1, r = n;
	ll sum = 0;
	while(l < r){
		ll mid = (l + r) >> 1;
		r = mid - 1;
		if(mid == l){
			sum += a;
		}
		else{
			sum += a + b;
		}
		dbg(sum, r, mid);
	}
	cout << sum;
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
