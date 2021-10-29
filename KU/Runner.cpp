/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Runner
 * ALGO		: Greedy, Math
 * DATE		: 29 Oct 2021
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

ll v[100100];

void solve(){
	ll n, k, s;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	sort(v + 1, v + n + 1);
	v[1] *= k;
	int cnt = 0;
	for(int i=2; i<=n; ++i){
		v[i] *= (k - 1);
		if(v[1] > v[i]){
			cnt++;
		}
	}
	cout << 1 + cnt;
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
