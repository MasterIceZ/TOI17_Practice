/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Mod of Power
 * ALGO		: Divide and Conquer
 * DATE		: 18 Aug 2021
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

ll divide(ll a, ll b, ll c){
	if(b == 1){
		return a % c;
	}
	ll tmp = divide(a, b/2, c);
	if(b % 2 == 0){
		return (tmp * tmp) % c;
	}
	return (((tmp * tmp) % c) * a) % c; 
}

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	cout << divide(a, b, c);
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
