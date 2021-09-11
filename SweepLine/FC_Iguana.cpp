/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Iguana
 * ALGO		: Sweepline
 * DATE		: 11 Sep 2021
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
	ll n, m, opr;
	cin >> n >> m;
	map<ll, ll> mp;
	for(int i=1, l, r; i<=m; ++i){
		cin >> l >> r;
		mp[min(l, r)]++, mp[max(l, r) + 1]--;
	}
	mp[1] += 0;
	mp[1 + n] = 0;
	char want;
	cin >> want;
	if(want == 'R'){
		opr = 0;
	}
	else if(want == 'G'){
		opr = 1;
	}
	else{
		opr = 2;
	}
	ll amt = 0, last = 1, sum = 0;
	for(auto x: mp){
		amt += ((opr + 3 - (sum % 3)) % 3) * (x.first - last);
		sum += x.second;
		last = x.first;
	}
	cout << amt;
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
